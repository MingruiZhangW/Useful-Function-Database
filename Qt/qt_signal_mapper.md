# Qt Signal Mapper

    QSignalMapper *signalMapper;

    //Adds a mapping so that when map() is signalled from the sender, the signal mapped(id) is emitted.
    signalMapper->setMapping(ui->panelButton_0, 0);
    signalMapper->setMapping(ui->panelButton_1, 1);
    signalMapper->setMapping(ui->panelButton_2, 2);
    signalMapper->setMapping(ui->panelButton_3, 3);
    signalMapper->setMapping(ui->panelButton_4, 4);
    signalMapper->setMapping(ui->panelButton_5, 5);
    signalMapper->setMapping(ui->panelButton_6, 6);
    signalMapper->setMapping(ui->panelButton_7, 7);
    signalMapper->setMapping(ui->panelButton_8, 8);
    signalMapper->setMapping(ui->panelButton_9, 9);
    signalMapper->setMapping(ui->panelButton_hash, 10);
    signalMapper->setMapping(ui->panelButton_star, 11);

    connect(ui->panelButton_0, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(ui->panelButton_1, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(ui->panelButton_2, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(ui->panelButton_3, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(ui->panelButton_4, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(ui->panelButton_5, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(ui->panelButton_6, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(ui->panelButton_7, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(ui->panelButton_8, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(ui->panelButton_9, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(ui->panelButton_hash, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(ui->panelButton_star, SIGNAL(clicked()), signalMapper, SLOT(map()));

    connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(panelButtonClicked(int)));

clicked()->map()->(setMapping(object,id))->mapped(id)->panelButtonClicked(id)

https://doc.qt.io/qt-5/qsignalmapper.html#setMapping
