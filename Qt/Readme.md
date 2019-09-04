# Qt knowlodge

- [QT Run Powershell cmd](https://github.com/MingruiZhangW/Useful-Function-Database/blob/master/Qt/Qt_Run_Powershell_cmd.md)<br>
- [QT Network (Download Files HTTP)](https://github.com/MingruiZhangW/Useful-Function-Database/blob/master/Qt/downloadmanager.cpp)<br>
- [Drap and Drop area](https://wiki.qt.io/Drag_and_Drop_of_files)
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
[How Signal & Slot Works](https://woboq.com/blog/how-qt-signals-slots-work.html)<br>

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
