# Qt knowlodge

[QT Network (Download Files HTTP)](https://github.com/MingruiZhangW/Useful-Function-Database/blob/master/Qt/downloadmanager.cpp)<br>
[Drap and Drop area](https://wiki.qt.io/Drag_and_Drop_of_files)
- Convert QByteArray(base64) to QPixmap
```
QByteArray txt = "iVBORw0KGgoAAAANSUhEUgAAACgAAAAoCAYAAACM/rhtAAAAAXNSR0IArs4c6QAAAARnQU1BAACxjwv8YQUAAAAJcEhZcwAADsMAAA7DAcdvqGQAAADxSURBVFhH7ZSxDYMwEEW9RdqU9MhFOho6WrwAE0SsESGlyABpvEU2yB5ZItLFnG1kkJEgipUjuSdZWG78+HdnwTAMAR73J7gtXTYjOSd61Wc6PxCTJCXYM5X8muDldJi9OJQkKdjj+5KsoGcTgrHhSc5PJei2iVA1qNvRrBoyIYbLiAjmUBi5Sjc0BbPOJKdL2LVG0HzdMbJEMG16WNoGpBQUBW1pC2VLikl2OR3BqRAtQSzteCBigkv4vKAsoQpK65HaTHK7JyA4vHnxtVYy4ZCEjAdmDSyIYF/a99CdLCaxoE0u7MF3UmQYhmGYv0SIF0Zn9rmd3QoAAAAAAElFTkSuQmCC";

QPixmap image;
image.loadFromData(QByteArray::fromBase64(txt));
ui->label->setPixmap(image);
```
