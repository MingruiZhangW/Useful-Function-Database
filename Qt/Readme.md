# Qt knowlodge

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

# Qml && C++ Interaction
- [Overview](https://doc.qt.io/qt-5/qtqml-cppintegration-overview.html)<br>
- [Exposing Attributes of C++ Types to QML](https://doc.qt.io/qt-5/qtqml-cppintegration-exposecppattributes.html)<br>
- [Interacting with QML Objects from C++](https://doc.qt.io/qt-5/qtqml-cppintegration-interactqmlfromcpp.html)<br>

# Qmake
[A Guild to Qmake](https://www.toptal.com/qt/vital-guide-qmake)<br>
