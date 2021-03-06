# mainwindow: detect secondary instances of Jami and restore primary 

### Main.cpp

    QCoreApplication::setApplicationName("Ring");
    QCoreApplication::setOrganizationDomain("jami.net");

    QCryptographicHash appData(QCryptographicHash::Sha256);
    appData.addData(QApplication::applicationName().toUtf8());
    appData.addData(QApplication::organizationDomain().toUtf8());
    RunGuard guard(appData.result());
    if (!guard.tryToRun()) {
        return 0;
    }
    
### Runguard.h 
    /***************************************************************************
     * Copyright (C) 2019 by Savoir-faire Linux                                *
     * Author: Andreas Traczyk <andreas.traczyk@savoirfairelinux.com>          *
     *                                                                         *
     * This program is free software; you can redistribute it and/or modify    *
     * it under the terms of the GNU General Public License as published by    *
     * the Free Software Foundation; either version 3 of the License, or       *
     * (at your option) any later version.                                     *
     *                                                                         *
     * This program is distributed in the hope that it will be useful,         *
     * but WITHOUT ANY WARRANTY; without even the implied warranty of          *
     * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the           *
     * GNU General Public License for more details.                            *
     *                                                                         *
     * You should have received a copy of the GNU General Public License       *
     * along with this program.  If not, see <http://www.gnu.org/licenses/>.   *
     **************************************************************************/
    // Based on: https://stackoverflow.com/a/28172162

    #pragma once

    #include <QObject>
    #include <QSharedMemory>
    #include <QSystemSemaphore>
    #include <QtNetwork/QLocalServer>
    #include <QtNetwork/QLocalSocket>

    class RunGuard : public QObject
    {
        Q_OBJECT;
    public:
        RunGuard(const QString& key);
        ~RunGuard();

        bool isAnotherRunning();
        bool tryToRun();
        void release();

    private slots:
        void tryRestorePrimaryInstance();

    private:
        const QString key_;
        const QString memLockKey_;
        const QString sharedmemKey_;

        QSharedMemory sharedMem_;
        QSystemSemaphore memLock_;

        QLocalSocket *socket_;
        QLocalServer *server_;

        Q_DISABLE_COPY(RunGuard)
    };
### Runguard.cpp
    /***************************************************************************
     * Copyright (C) 2019 by Savoir-faire Linux                                *
     * Author: Andreas Traczyk <andreas.traczyk@savoirfairelinux.com>          *
     *                                                                         *
     * This program is free software; you can redistribute it and/or modify    *
     * it under the terms of the GNU General Public License as published by    *
     * the Free Software Foundation; either version 3 of the License, or       *
     * (at your option) any later version.                                     *
     *                                                                         *
     * This program is distributed in the hope that it will be useful,         *
     * but WITHOUT ANY WARRANTY; without even the implied warranty of          *
     * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the           *
     * GNU General Public License for more details.                            *
     *                                                                         *
     * You should have received a copy of the GNU General Public License       *
     * along with this program.  If not, see <http://www.gnu.org/licenses/>.   *
     **************************************************************************/
     // Based on: https://stackoverflow.com/a/28172162

    #include "runguard.h"

    #include <QCryptographicHash>

    #include "mainwindow.h"

    namespace
    {

    QString generateKeyHash(const QString& key, const QString& salt)
    {
        QByteArray data;

        data.append(key.toUtf8());
        data.append(salt.toUtf8());
        data = QCryptographicHash::hash(data, QCryptographicHash::Sha1).toHex();

        return data;
    }

    }

    RunGuard::RunGuard(const QString& key)
        : key_(key)
        , memLockKey_(generateKeyHash(key, "_memLockKey"))
        , sharedmemKey_(generateKeyHash(key, "_sharedmemKey"))
        , sharedMem_(sharedmemKey_)
        , memLock_(memLockKey_, 1)
    {}

    RunGuard::~RunGuard()
    {
        release();
    }

    void
    RunGuard::tryRestorePrimaryInstance()
    {
        MainWindow::instance().showWindow();
    }

    bool RunGuard::isAnotherRunning()
    {
        if (sharedMem_.isAttached())
            return false;

        memLock_.acquire();
        //You need to create() the shared memory segment in one of the processes which are using it. Most likely, you have one "master"         //or "server" process which is started first - let this process create the shared memory with a specific size:
        const bool isRunning = sharedMem_.attach();
        if (isRunning)
            sharedMem_.detach();
        memLock_.release();

        return isRunning;
    }

    bool RunGuard::tryToRun()
    {
        if (isAnotherRunning()) {
            // This is a secondary instance,
            // connect to the primary instance to trigger a restore
            // then fail.
            if (socket_ == nullptr) {
                socket_ = new QLocalSocket();
            }
            if (socket_->state() == QLocalSocket::UnconnectedState ||
                socket_->state() == QLocalSocket::ClosingState) {
                socket_->connectToServer(key_);
            }
            if (socket_->state() == QLocalSocket::ConnectingState) {
                socket_->waitForConnected();
            }
            return false;
        }

        memLock_.acquire();
        const bool result = sharedMem_.create(sizeof(quint64));
        memLock_.release();
        if (!result) {
            release();
            return false;
        }

        // This is the primary instance,
        // listen for subsequent instances.
        QLocalServer::removeServer(key_);
        server_ = new QLocalServer();
        server_->setSocketOptions(QLocalServer::UserAccessOption);
        server_->listen(key_);
        QObject::connect(
            server_,
            &QLocalServer::newConnection,
            this,
            &RunGuard::tryRestorePrimaryInstance
        );

        return true;
    }

    void RunGuard::release()
    {
        memLock_.acquire();
        if (sharedMem_.isAttached())
            sharedMem_.detach();
        memLock_.release();
    }
