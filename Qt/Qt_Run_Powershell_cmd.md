 # Qt Run Powershell cmd
    auto args = QString(" /passive /norestart WIXNONUILAUNCH=1");
    auto dir = QString("C:\\Users\\mzhang\\Desktop");
    auto cmd = "powershell " + dir + "\\Jami.msi"
        + " /L*V " + dir + "\\jami_install.log" + args;
    auto retq = QProcess::startDetached(cmd);
    if (retq) {
        QApplication::quit();
    }
