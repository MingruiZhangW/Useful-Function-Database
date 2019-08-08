# Check if Rect Contains QPoint

    QMouseEvent *event
    auto relativeCursorPos = ui->transferCallButton->mapFromGlobal(event->pos());
    if (!ui->transferCallButton->rect().contains(relativeCursorPos)) {
        ui->transferCallButton->setChecked(false);
    }
    
https://doc.qt.io/qt-5/qrect.html
https://doc.qt.io/qt-5/qwidget.html#mapFromGlobal
