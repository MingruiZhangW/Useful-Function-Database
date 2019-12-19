# Qml Loading Method

### QQuickWidget

```
QQuickWidget* widg = new QQuickWidget(QUrl(QStringLiteral("qrc:/src/KeyBoardShortcutTable.qml")), this);
widg->setMouseTracking(true);
widg->setWindowFlags(Qt::Widget | Qt::FramelessWindowHint);
widg->setAttribute(Qt::WA_AlwaysStackOnTop);
widg->setClearColor(Qt::transparent);
widg->resize(650, 400);
widg->raise();
widg->show();
widg->move(this->rect().center() - widg->rect().center());

widg->setMaximumWidth(widg->rootObject()->property("minWidth").toInt());
widg->setMinimumHeight(widg->rootObject()->property("minHeight").toInt());
widg->setParent(dialog);
dialog->insertWidget(widg);
dialog->exec();

return true;
```

### QQuickView
```
QQuickView* view = new QQuickView(QUrl("qrc:/src/KeyBoardShortcutTable.qml"));

QWidget* container = QWidget::createWindowContainer(view, this);
container->setMouseTracking(true);
container->setWindowFlags(Qt::Widget | Qt::FramelessWindowHint);
container->setMinimumWidth(view->rootObject()->property("minWidth").toInt());
container->setMinimumHeight(view->rootObject()->property("minHeight").toInt());
container->setParent(dialog);
widg->setParent(dialog);
dialog->insertWidget(widg);
container->move(this->rect().center() - container->rect().center());
container->show();
dialog->exec();*/
return true;
```

### QQmlApplicationEngine
```
QQmlApplicationEngine engine;
engine.load(QUrl("qrc:/src/main.qml"));

QList<QObject*> temp = engine.rootObjects();
QObject* topLevel = temp.value(0);
QQuickWindow* window = qobject_cast<QQuickWindow*>(topLevel);
QObject* tableView = window->findChild<QObject*>("tableView1");

if (!window) {
    qWarning("Error: Your root item has to be a Window.");
    return -1;
}

QQmlComponent component(&engine, QUrl(QStringLiteral("qrc:/src/KeyBoardShortcutTable.qml")));
QObject* childItem = qobject_cast<QObject*>(component.create());
childItem->setParent(window);
window->show();
```
https://doc.qt.io/qt-5/qtqml-cppintegration-interactqmlfromcpp.html
