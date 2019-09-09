# Qt - Draw Rounded Edge Photo

    QImage
    Utils::getRoundedEdgePhoto(const QImage original, int widthPhoto, int heightPhoto, int roundness)
    {
        // First, create a transparent image with the same size
        QImage target(widthPhoto, heightPhoto, QImage::Format_ARGB32_Premultiplied);
        target.fill(Qt::transparent);

        //Second, create a painter onto that image
        QPainter painter(&target);
        painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
        painter.setBrush(QBrush(original));
        // set brush to the image that we want to draw
        // Note that, the Qbrush is in default texture mode

        //Third, scale the original image into the size of the image we created
        auto scaledPhoto = original
                .scaled(widthPhoto, heightPhoto, Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation)
                .convertToFormat(QImage::Format_ARGB32_Premultiplied);
        painter.drawRoundedRect(0, 0, widthPhoto, heightPhoto, roundness, roundness);
        painter.setCompositionMode(QPainter::CompositionMode_SourceIn);
        // Source-In mode and Draw the image onto the transperant image
        painter.drawImage(0, 0, scaledPhoto, 0, 0);
        return target;
    }
