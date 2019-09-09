# QT - Draw Black Circular Widget

    void
    Utils::drawBlackCircularWidget(QWidget* widget)
    {
        // Widget is black, fill image with white
        // draw a black cycle onto it
        QImage target(widget->width(), widget->height(), QImage::Format_ARGB32_Premultiplied);
        target.fill(Qt::white);

        QPainter painter(&target);
        painter.setBrush(QBrush(Qt::black));
        painter.drawEllipse(widget->x(), widget->y(), widget->width() -5, widget->height() - 5);
        painter.setCompositionMode(QPainter::CompositionMode_SourceIn);
        widget->setMask(QBitmap::fromImage(target, Qt::ColorOnly));
    }
