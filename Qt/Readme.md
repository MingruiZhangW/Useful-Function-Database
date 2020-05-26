# Qt knowlodge

**Important**
### [Object Trees & Ownership](https://doc.qt.io/archives/qt-4.8/objecttrees.html)
```
When QObjects are created on the heap (i.e., created with new), a tree can be constructed from them in any order, and later, the objects in the tree can be destroyed in any order. When any QObject in the tree is deleted, if the object has a parent, the destructor automatically removes the object from its parent. If the object has children, the destructor automatically deletes each child. No QObject is deleted twice, regardless of the order of destruction.
```


```
QcoreApplication -> non-gui based application (complier)
QGuiApplication -> mainly qml
QApplication -> Qwidget bases application
```
- [QT Layout Managment](https://doc.qt.io/qt-5/layout.html)<br>
- [QT Crash Course/ Event Loop](https://www.cleanqt.io/blog/crash-course-in-qt-for-c%2B%2B-developers,-part-1)<br>
- [QT Run Powershell cmd](https://github.com/MingruiZhangW/Useful-Function-Database/blob/master/Qt/Qt_Run_Powershell_cmd.md)<br>
- [QT Network (Download Files HTTP)](https://github.com/MingruiZhangW/Useful-Function-Database/blob/master/Qt/downloadmanager.cpp)<br>
- [Drap and Drop area](https://wiki.qt.io/Drag_and_Drop_of_files)<br>
- [Qt MultiThreading](https://toptal.com/qt/qt-multithreading-c-plus-plus)<br>
- [QSettings - File Location](https://stackoverflow.com/questions/4031838/qsettings-where-is-the-location-of-the-ini-file)<br>
- [Qt - Delete all file except certain file](https://github.com/MingruiZhangW/Useful-Function-Database/blob/master/Qt/Qt_Delete_File.md)<br>
- Convert QByteArray(base64) to QPixmap
```
QByteArray txt = "iVBORw0KGgoAAAANSUhEUgAAACgAAAAoCAYAAACM/rhtAAAAAXNSR0IArs4c6QAAAARnQU1BAACxjwv8YQUAAAAJcEhZcwAADsMAAA7DAcdvqGQAAADxSURBVFhH7ZSxDYMwEEW9RdqU9MhFOho6WrwAE0SsESGlyABpvEU2yB5ZItLFnG1kkJEgipUjuSdZWG78+HdnwTAMAR73J7gtXTYjOSd61Wc6PxCTJCXYM5X8muDldJi9OJQkKdjj+5KsoGcTgrHhSc5PJei2iVA1qNvRrBoyIYbLiAjmUBi5Sjc0BbPOJKdL2LVG0HzdMbJEMG16WNoGpBQUBW1pC2VLikl2OR3BqRAtQSzteCBigkv4vKAsoQpK65HaTHK7JyA4vHnxtVYy4ZCEjAdmDSyIYF/a99CdLCaxoE0u7MF3UmQYhmGYv0SIF0Zn9rmd3QoAAAAAAElFTkSuQmCC";

QPixmap image;
image.loadFromData(QByteArray::fromBase64(txt));
ui->label->setPixmap(image);
```

- [QT Tab Order](https://doc.qt.io/archives/qt-4.8/designer-tab-order.html)<br>
- [QT WindowModality](https://doc.qt.io/qt-5/qt.html#WindowModality-enum)<br>
- [QT Modal Dialog](https://doc.qt.io/qt-5/qdialog.html#modal-dialogs)<br>
- [QT Rect/QPoint Contain](https://github.com/MingruiZhangW/Useful-Function-Database/blob/master/Qt/Check%20if%20a%20Widget%20contains%20QPoint.md)<br>
- [QT Use QString Effectively](https://wiki.qt.io/Using_QString_Effectively)<br>
### QT Block Signal General Functions
[BlockSignals](https://github.com/MingruiZhangW/Useful-Function-Database/blob/master/Qt/QT%20BlockSignal%20General%20Function.md)<br>

### QT Signal & SLot
> [How Signal & Slot Works](https://woboq.com/blog/how-qt-signals-slots-work.html)<br>
> [Qt signals (QueuedConnection and DirectConnection)](https://stackoverflow.com/questions/15051553/qt-signals-queuedconnection-and-directconnection)<br>

### QT KeyBoard Event
[KeyBoard Press Event](https://www.qtcentre.org/threads/693-Capture-a-keyboard-event)<br>

### QT Signal Mappper
[Signal Mapper & setMapping](https://github.com/MingruiZhangW/Useful-Function-Database/blob/master/Qt/qt_signal_mapper.md)<br>

### QT Property System
[Qt Property](https://doc.qt.io/qt-5/properties.html)<br>
- By adding dynamic properties in QT Creator, and set Q_Property DESIGNABLE true, we can add customize properties into our customized widgets. ([Example](https://github.com/MingruiZhangW/Useful-Function-Database/blob/master/Qt/overlay.h))

# QT Promote a Widget
- [QT Customize Widget Promoting](https://doc.qt.io/qt-5/designer-using-custom-widgets.html#promoting-widgets)<br>
- [Widget Promote Global Include](https://stackoverflow.com/questions/24031774/what-does-the-global-include-checkbox-mean-in-the-promoted-widgets-dialog)<br>

# QT Widget VS Window VS Dialog
- Widget: A rectangular region on the screen for display and user interaction. They include buttons, sliders, views, dialogs, windows, etc. All widgets will display something on the screen, and many will also accept user input from the keyboard or mouse. The word "widget" comes from Unix, on Windows they are called "controls".

- Window: A "top level" widget. A window is the top of a parent/child hiearchy, and are usually displayed with a titlebar and border. The underlying windowing system (Windows, KDE, GNOME, etc) will provide policies for the windows, such as titlebar/border style, placement, focus, etc.

- Dialog: A special kind of window, usually temporary. They may or may not have a different titlebar appearance. They are presented to the user for the purpose of notification or gathering input, and typically have OK, Cancel, etc., buttons on the bottom or right.

> The key here is that all of these are widgets, windows are the top-level widgets, and dialogs are a special kind of window.

# QT Message Box With Answer/Respond
```
    QMessageBox::StandardButton resBtn = QMessageBox::question(this, "Update",
        tr("Quit Update?\n"),
        QMessageBox::Cancel | QMessageBox::No | QMessageBox::Yes,
        QMessageBox::Yes);
    if (resBtn == QMessageBox::Yes) {
        emit isCanceled();
    } else {
        event->ignore();
    }
```
# QT QParallelAnimationGroup Class And Usage
[QParallelAnimationGroup--a container for animations--starts all its animations when it is started itself, i.e., runs all animations in parallel. The animation group finishes when the longest lasting animation has finished.](https://doc.qt.io/qt-5/qparallelanimationgroup.html)<br>
>[Usage](https://stackoverflow.com/questions/32476006/how-to-make-an-expandable-collapsable-section-widget-in-qt)<br>

# QT - How can I hide/delete the “?” help button on the “title bar” of a Qt Dialog?
`setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);`<br>
https://stackoverflow.com/questions/81627/how-can-i-hide-delete-the-help-button-on-the-title-bar-of-a-qt-dialog`

# Qt: How do I handle the event of the user pressing the 'X' (close) button?
```
#include <QCloseEvent>
void MainWindow::closeEvent (QCloseEvent *event)
{
    QMessageBox::StandardButton resBtn = QMessageBox::question( this, APP_NAME,
                                                                tr("Are you sure?\n"),
                                                                QMessageBox::Cancel | QMessageBox::No | QMessageBox::Yes,
                                                                QMessageBox::Yes);
    if (resBtn != QMessageBox::Yes) {
        event->ignore();
    } else {
        event->accept();
    }
}
```
https://stackoverflow.com/questions/17480984/qt-how-do-i-handle-the-event-of-the-user-pressing-the-x-close-button

# Qt Object Destory Chain
- [Doc](https://doc.qt.io/archives/qt-4.8/objecttrees.html)<br>
```
QObjects organize themselves in object trees. When you create a QObject with another object as parent, it's added to the parent's children() list, and is deleted when the parent is. It turns out that this approach fits the needs of GUI objects very well. For example, a QShortcut (keyboard shortcut) is a child of the relevant window, so when the user closes that window, the shorcut is deleted too.
```
# QML
- [QML Loading method](https://github.com/MingruiZhangW/Useful-Function-Database/blob/master/Qt/qml.md)<br>
+ [Difference Between QQmlapplicationengine and QQuickview](https://forum.qt.io/topic/72516/what-is-the-difference-between-qqmlapplicationengine-and-qquickview)<br>
+ [Windeployqt qml deply](https://stackoverflow.com/questions/53160127/windeployqt-module-qtquick-not-installed)<br>
+ [Row height change in tableview](https://stackoverflow.com/questions/25522719/how-to-correctly-change-the-row-height-of-a-tableview)<br>
+ [Qml Property Binding (like height, width)](https://doc.qt.io/qt-5/qtqml-syntax-propertybinding.html)<br>
+ [Models and Views in QtQuick](https://doc.qt.io/qt-5/qtquick-modelviewsdata-modelview.html#qml-data-models)<br>
+ [QML TableView access model properties from delegate](https://stackoverflow.com/questions/22874387/qml-tableview-access-model-properties-from-delegate)<br>
+ [How to access data in QML TableViewColumn delegate?](https://stackoverflow.com/questions/19577210/how-to-access-data-in-qml-tableviewcolumn-delegate/26809548)<br>
+ [Dynamic QML Object Creation from JavaScript](https://doc.qt.io/qt-5/qtqml-javascript-dynamicobjectcreation.html)<br>
+ [QML: How can I pass model properties to a delegate loaded inside a GridView (or ListView) delegate?](https://stackoverflow.com/questions/8450992/qml-how-can-i-pass-model-properties-to-a-delegate-loaded-inside-a-gridview-or)<br>
- [Customizing Qt Quick Controls](https://doc.qt.io/qt-5/qtquickcontrols2-customize.html#customizing-button)<br>
- [Qml Mouse Absolute Pos](https://stackoverflow.com/questions/19392163/qml-mouse-absolute-position-in-mousearea/44779025#44779025)<br>
- [Property signal - Does an Item emit a signal when its position/size is changed in QML?](https://stackoverflow.com/questions/19987177/does-an-item-emit-a-signal-when-its-position-size-is-changed-in-qml)<br>
https://forum.qt.io/topic/64041/textfield-and-mousearea
- [Scroll Bar AsNeeded](https://stackoverflow.com/questions/51961813/qml-scrollbar-asneeded)<br>
- [MapToItem Qml](https://stackoverflow.com/questions/21001124/what-is-the-qquickitemmaptoitem-return-type)<br>
### Qml ClipBoard
- [Qml and c++ QClipBoard](https://ruedigergad.com/2011/08/06/qml-and-clipboard-interaction/?unapproved=11929&moderation-hash=90a2276746f2445ad9fdd8464cdb66b5#comment-11929)<br>

### QWindow & QWedget
- [What is the difference between a QWindow and QWidget](https://stackoverflow.com/questions/17860604/what-is-the-difference-between-a-qwindow-and-qwidget)<br>

### Qml Image Loading
+ [Qt/QML : Send QImage From C++ to QML and Display The QImage On GUI](https://stackoverflow.com/questions/20691414/qt-qml-send-qimage-from-c-to-qml-and-display-the-qimage-on-gui)<br>

# Qml && C++ Interaction
- [Overview](https://doc.qt.io/qt-5/qtqml-cppintegration-overview.html)<br>
- [Exposing Attributes of C++ Types to QML](https://doc.qt.io/qt-5/qtqml-cppintegration-exposecppattributes.html)<br>
- [Interacting with QML Objects from C++](https://doc.qt.io/qt-5/qtqml-cppintegration-interactqmlfromcpp.html)<br>

```
Every QML object can be assigned an id and an objectName that other objects can use to refer to the object.
The difference between the two is that the id is for referencing the object within QML,
while the objectName is required for referencing the object from C++
```

- [Model in c++ To Qml](https://wiki.qt.io/How_to_Use_a_Custom_Class_in_C%2B%2B_Model_and_QML_View)<br>
- [Using C++ Models with Qt Quick Views](https://doc.qt.io/qt-5/qtquick-modelviewsdata-cppmodels.html)<br>

# Qml Customiziation Example

- [QtQuick2 ComboBox with sections](https://stackoverflow.com/questions/44849497/qtquick2-combobox-with-sections)<br>

- Responsive rect
```
    Component {
        id: welcomeRectComp

        Rectangle {
            id: welcomeRect

            Rectangle{
                id: welcomeRectComponentsGroup

                anchors.centerIn: parent

                //width: 300
                //height: mainViewWindow.minimumHeight
                width: parent.width - 100
                height: parent.height - 200

                ColumnLayout {
                    id: welcomeRectComponentsGroupColumnLayout

                    Image {
                        id: jamiLogoImage

                        Layout.alignment: Qt.AlignCenter
                        Layout.preferredWidth: welcomeRectComponentsGroup.width
                        Layout.preferredHeight: 100

                        fillMode: Image.PreserveAspectFit
                        source: "qrc:/images/logo-jami-standard-coul.png"
                        mipmap: true
                    }

                    Label {
                        id: jamiIntroText

                        Layout.alignment: Qt.AlignCenter
                        Layout.preferredWidth: welcomeRectComponentsGroup.width
                        Layout.preferredHeight: 100

                        wrapMode: Text.WordWrap
                        fontSizeMode: Text.Fit
                        font.pointSize: textFontSize + 1
                        minimumPointSize: 5
                        elide: Text.ElideRight

                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter

                        text: "Jami is a free software for universal communication which repects the freedoms and privacy of its user."

                        background: Rectangle {
                            color: "yellow"
                        }
                    }

                    Label {
                        id: jamiShareWithFriendText

                        Layout.alignment: Qt.AlignCenter
                        Layout.preferredWidth: welcomeRectComponentsGroup.width
                        Layout.preferredHeight: 50
                        Layout.topMargin: 5

                        wrapMode: Text.WordWrap
                        fontSizeMode: Text.Fit
                        minimumPointSize: 5
                        font.pointSize: textFontSize - 1
                        elide: Text.ElideRight

                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter

                        text: "This is your ID.\nCopy and share it with your friends"

                        background: Rectangle {
                            color: "orange"
                        }
                    }

                }
                color: "blue"
            }

            CustomBorder {
                commonBorder: false
                lBorderwidth: 1
                rBorderwidth: 0
                tBorderwidth: 0
                bBorderwidth: 0
                borderColor: ColorConstant.tabbarBorderColor
            }
            color: "pink"
        }
    }
```

### Qml HyperText

```
Text {
    anchors.centerIn: parent
    text: "To learn about KDE, <a href='http://www.kde.org'>click here</a>"
    onLinkActivated: Qt.openUrlExternally(link)

    MouseArea {
        anchors.fill: parent
        acceptedButtons: Qt.NoButton // we don't want to eat clicks on the Text
        cursorShape: parent.hoveredLink ? Qt.PointingHandCursor : Qt.ArrowCursor
    }
}
```

# Cpp Structure in QMl 
[Cpp Structure In Qml](https://forum.qt.io/topic/82325/best-way-to-access-a-cpp-structure-in-qml/9)<br>
```
struct MyStruct {
    Q_GADGET
    int m_val;
    QString m_name1;
    QString m_name2;
    QString m_name3;
    QString m_name4;
    Q_PROPERTY(int val MEMBER m_val)
    Q_PROPERTY(QString name1 MEMBER m_name1)
    Q_PROPERTY(QString name2 MEMBER m_name2)
    Q_PROPERTY(QString name3 MEMBER m_name3)
    Q_PROPERTY(QString name4 MEMBER m_name4)
};
```
# QML WebEngine
- [Doc](https://retifrav.github.io/blog/2018/07/14/html-from-qml-over-webchannel-websockets/)<br>

# QML oneShotConnect
[oneShotConnect](https://stackoverflow.com/questions/45019082/connect-signal-to-slot-but-call-the-slot-only-once-and-then-auto-disconnect-the)<br>

# Qmake
[A Guild to Qmake](https://www.toptal.com/qt/vital-guide-qmake)<br>

# Solve Qml App Flickers When Resize or Move Issue
https://stackoverflow.com/questions/30818886/qml-window-resize-move-flicker

# QMl - Js Signal Connection
https://stackoverflow.com/questions/18647604/is-it-possible-to-connect-a-signal-from-javascript-to-qml

# Qml -Force update by adding extra dependency
http://www.mardy.it/blog/2016/11/qml-trick-force-re-evaluation-of.html
```
Repeater {
        model: 10
        Text {
            text: {theItem.something; return theItem.computeWithSomething(index);}
        }
    }
```

# C++ Enum/NameSpace QML Declare (support multiple enum)
- **c++ Step 1 (lrc)**
```
namespace lrc {
namespace api {
namespace account {
    Q_NAMESPACE
    Q_CLASSINFO("RegisterEnumClassesUnscoped", "false")

    enum class RegisterNameStatus {
        SUCCESS = 0,
        WRONG_PASSWORD = 1,
        INVALID_NAME = 2,
        ALREADY_TAKEN = 3,
        NETWORK_ERROR = 4,
        INVALID
    };
    Q_ENUMS(RegisterNameStatus)

    enum class LookupStatus {
        INVALID_NAME = 0,
        SUCCESS = 1,
        NOT_FOUND = 2,
        ERROR = 3,
        INVALID
    };
    Q_ENUMS(LookupStatus)
}

namespace conversation {
    Q_NAMESPACE
    Q_CLASSINFO("RegisterEnumClassesUnscoped", "false")

    enum class Test {
        SUCCESS = 2
    };
    Q_ENUMS(Test)
}
}
}
```
- **c++ Step 2 (qml-client)**

qmlRegisterUncreatableMetaObject(lrc::api::account::staticMetaObject,
                                     "lrc.api", 1, 0, "Account", "");

qmlRegisterUncreatableMetaObject(lrc::api::conversation::staticMetaObject,
                                     "lrc.api", 1, 0, "Conversation", "");
- **qml Step 3**
```
import lrc.api 1.0
...
console.log(Account.RegisterNameStatus.SUCCESS)
console.log(Account.LookupStatus.SUCCESS)
console.log(Conversation.Test.SUCCESS)
```

[**QML Enum**](https://evileg.com/en/post/314/)
