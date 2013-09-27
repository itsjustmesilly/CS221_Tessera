// define slot somewhere for all actions that is empty
//

#include "MainWindow.h"

MainWindow::MainWindow()
{
    createActions();
    createMenus();
    createWidgets();
    createToolBars();
    createDockWidget();
  //  QSplitter *rightsplitter = new QSplitter(Qt::Vertical);
  //  rightsplitter->addWidget(m_tabs);
  //  rightsplitter->setStretchFactor(0,1);
}

void MainWindow::createDockWidget()
{
    QDockWidget *dock = new QDockWidget(this);
    dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);

    listInDock = new QListWidget(dock);
    //listInDock->addItems(QStringList());

    dock->setWidget(listInDock);
    addDockWidget(Qt::RightDockWidgetArea, dock);

    viewMenu->addAction(dock->toggleViewAction());

    QTreeWidget *treeWidget = new QTreeWidget(listInDock);

    QTreeWidgetItem *inputSettings = new QTreeWidgetItem(treeWidget);
    inputSettings->setText(0, tr("Input Settings"));

    QTreeWidgetItem *brightItem = new QTreeWidgetItem(inputSettings);
    brightItem->setText(0, tr("Bright/Contrast"));
    brightItem->setText(1, tr("Yes"));

    QTreeWidgetItem *hueItem = new QTreeWidgetItem(inputSettings);
    hueItem->setText(0, tr("Hue/Saturation"));
    hueItem->setText(1, tr("Yes"));

    QTreeWidgetItem *mosaicSize = new QTreeWidgetItem(treeWidget);
    mosaicSize->setText(0, tr("Mosaic Size"));

    QTreeWidgetItem *mosaicSizeItem = new QTreeWidgetItem(mosaicSize);
    mosaicSizeItem->setText(0, tr("Oslo"));
    mosaicSizeItem->setText(1, tr("Yes"));

    QTreeWidgetItem *mosaicRender = new QTreeWidgetItem(treeWidget);
    mosaicRender->setText(0, tr("Mosaic Rendering"));
    QTreeWidgetItem *mosaicRenderItem = new QTreeWidgetItem(mosaicRender);
    mosaicRenderItem->setText(0, tr("Oslo"));
    mosaicRenderItem->setText(1, tr("Yes"));

    QTreeWidgetItem *tilePallette = new QTreeWidgetItem(treeWidget);
    tilePallette->setText(0, tr("Tile Pallette"));
    QTreeWidgetItem *tilePalletteItem = new QTreeWidgetItem(tilePallette);
    tilePalletteItem->setText(0, tr("Oslo"));
    tilePalletteItem->setText(1, tr("Yes"));

    QTreeWidgetItem *grout = new QTreeWidgetItem(treeWidget);
    grout->setText(0, tr("Grout"));
    QTreeWidgetItem *groutItem = new QTreeWidgetItem(grout);
    groutItem->setText(0, tr("Oslo"));
    groutItem->setText(1, tr("Yes"));

    QTreeWidgetItem *test = new QTreeWidgetItem(treeWidget);
    test->setText(0, tr("TEST"));
    QTreeWidgetItem *testItem = new QTreeWidgetItem(test);
    testItem->setText(0, tr("TEST"));
    testItem->setText(1, tr("Yes"));

}

void MainWindow::createWidgets()//
{
    //Program Title Bar
    const char project[]="Homework 1";
    const char name1[]="Zsuzsanna Pote";
    const char name2[]="Donald Villarreal";
    const char name3[]="Joseph Wagner";
    const char date[]="09/26/2013";
    QString title = QString("%1 - by %2, %3, %4 - %5")
            .arg(project).arg(name1).arg(name2).arg(name3).arg(date);
    setWindowTitle(title);

    //create tab widgets
    m_tabs = new QTabWidget();
    m_tabs->addTab(m_input = new QTextEdit, "Input");
    m_tabs->addTab(m_output = new QTextEdit, "Output");
    m_tabs->addTab(m_palette = new QTextEdit, "Palette");
    m_tabs->addTab(m_info = new QTextEdit, "Info");

    //create brightness/contrast
    /*brMenu = new QWidget;
    brightSlide = new QSlider;
    brightSlide->setRange(-50,50);
    brightSlide->setValue(0);
    conSlide = new QSlider;
    conSlide->setRange(-50,50);
    conSlide->setValue(0);

    brradio = new QRadioButton;*/

    //code for right side (dock)
    //..........................

    //create splitter
    mainSplitter = new QSplitter(Qt::Horizontal);
    mainSplitter->addWidget(m_tabs);
    //mainSplitter->addWidget(m_dock);
    mainSplitter->setStretchFactor(0,1);
    setCentralWidget(mainSplitter);
}

void MainWindow::createMenus()
{
    //file menu
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newAction);
    fileMenu->addAction(openAction);
    fileMenu->addAction(loadAction);
    fileMenu->addSeparator();
    fileMenu->addAction(saveAction);
    fileMenu->addAction(saveAsAction);
    fileMenu->addSeparator();
    fileMenu->addAction(savePaletteAction);
    fileMenu->addAction(loadPaletteAction);
    fileMenu->addSeparator();
    fileMenu->addAction(exportAction);
    fileMenu->addAction(quitAction);

    //edit menu
    editMenu = menuBar()->addMenu(tr("&Edit"));
    editMenu->addAction(undoAction);
    editMenu->addAction(redoAction);
    editMenu->addSeparator();
    editMenu->addAction(cutAction);
    editMenu->addAction(copyAction);
    editMenu->addAction(pasteAction);
    editMenu->addAction(fillSelectionAction);
    editMenu->addAction(blendToolAction);
    editMenu->addAction(copyCurrLayerAction);
    editMenu->addSeparator();
    editMenu->addAction(resetParamAction);
    editMenu->addSeparator();
    editMenu->addAction(cropInputAction);
    editMenu->addAction(cropOutputAction);

    //view menu
    viewMenu = menuBar()->addMenu(tr("&View"));
    viewMenu->addAction(zoomInAction);
    viewMenu->addAction(zoomOutAction);
    viewMenu->addAction(fitWindowAction);
    viewMenu->addAction(fullscreenAction);
    viewMenu->addSeparator();
    viewMenu->addAction(toggleAction);
    viewMenu->addAction(layerMngrAction);
    viewMenu->addSeparator();
    viewMenu->addAction(inputAction);
    viewMenu->addAction(outputAction);
    viewMenu->addAction(paletteAction);
    viewMenu->addAction(infoAction);
}

void MainWindow::createToolBars()
{
    fileToolBar = addToolBar(tr("&File"));
    fileToolBar->addAction(newAction);
    fileToolBar->addAction(loadAction);
    fileToolBar->addAction(saveAction);

    viewToolBar = addToolBar(tr("&View"));
    viewToolBar->addAction(zoomInAction);
    viewToolBar->addAction(zoomOutAction);
    viewToolBar->addAction(layerMngrAction);
}

void MainWindow::createActions()
{
    //file menu
    newAction = new QAction(QIcon(":/icons/icons/file-save.png"), tr("Cu&t"), this);
    newAction->setIcon(QIcon(":icons/icons/file-new.png"));
    newAction->setShortcut(tr("Ctrl+N"));
    newAction->setStatusTip(tr("Create a new file"));
    //connect(newAction, SIGNAL(triggered()), this, SLOT(newFile()));

    openAction = new QAction(QIcon(":/icons/icons/file-save.png"),tr("&Open Examples"),this);
    openAction->setIcon(QIcon(":/icons/icons/file-new.png"));
    openAction->setShortcut(tr("Ctrl+O"));
    openAction->setStatusTip(tr("Open Example"));
    //connect(openAction, SIGNAL(triggered()), this, SLOT(openExample()));

    loadAction = new QAction(QIcon(":/icons/icons/file-save.png"),tr("&Load Project"),this);
    loadAction->setIcon(QIcon(":/icons/icons/file-load.png"));
    loadAction->setShortcut(tr("Ctrl+L"));
    loadAction->setStatusTip(tr("Open Existing Project"));
    //connect(loadAction, SIGNAL(triggered()), this, SLOT(openFile()));

    saveAction = new QAction(QIcon(":/icons/icons/file-save.png"),tr("&Save"),this);
    saveAction->setIcon(QIcon(":/icons/icons/file-save.png"));
    saveAction->setShortcut(tr("Ctrl+S"));
    saveAction->setStatusTip(tr("Save your current file"));
    //connect(saveAction, SIGNAL(triggered()), this, SLOT(saveFile()));

    saveAsAction = new QAction(QIcon(":/icons/icons/file-save.png"),tr("Save As..."),this);
    saveAsAction->setIcon(QIcon(":/icons/icons/file-save.png"));
    saveAsAction->setShortcut(tr("Ctrl+Shift+S"));
    saveAsAction->setStatusTip(tr("Save file with new name"));
    //connect(saveAsAction, SIGNAL(triggered()), this, SLOT(saveAsFile()));

    savePaletteAction = new QAction(tr("Save &Palette"),this);
    //savePaletteAction->setIcon()
    savePaletteAction->setShortcut(tr("Ctrl+P"));
    savePaletteAction->setStatusTip(tr("Save your current palette"));
    //connect(savePaletteAction, SIGNAL(triggered()), this, SLOT(savePalette()));

    loadPaletteAction = new QAction(tr("Load Palette"),this);
    //loadPaletteAction->setIcon()
    loadPaletteAction->setShortcut(tr("Ctrl+G"));
    loadPaletteAction->setStatusTip(tr("Load an existing palette"));
    //connect(loadPaletteAction, SIGNAL(triggered()), this, SLOT(loadPalette()));

    exportAction = new QAction(tr("&Export"),this);
    //exportAction->setIcon()
    exportAction->setShortcut(tr("Ctrl+E"));
    exportAction->setStatusTip(tr("Export project"));
    //connect(exportAction, SIGNAL(triggered()), this, SLOT(fileexport()));
    //
    quitAction = new QAction(tr("&Quit"),this);
    //quitAction->setIcon()
    quitAction->setShortcut(tr("Ctrl+Q"));
    quitAction->setStatusTip(tr("Quit Program"));
    //connect(quitAction, SIGNAL(triggered()), this, SLOT(filequit()));

    //edit menu
    undoAction = new QAction(tr("Undo"),this);
    //undoAction->setIcon()
    undoAction->setShortcut(tr("Ctrl+Z"));
    undoAction->setStatusTip(tr("Undo previous action"));
    //connect(undoAction, SIGNAL(triggered()), this, SLOT(undo()));

    redoAction = new QAction(tr("Redo"),this);
    //redoAction->setIcon()
    redoAction->setShortcut(tr("Ctrl+Y"));
    redoAction->setStatusTip(tr("Redo action"));
    //connect(redoAction, SIGNAL(triggered()), this, SLOT(redo()));

    cutAction = new QAction(tr("Cut"),this);
    //cutAction->setIcon()
    cutAction->setShortcut(tr("Ctrl+X"));
    cutAction->setStatusTip(tr("Cut selection"));
    //connect(cutAction, SIGNAL(triggered()), this, SLOT(cut()));

    copyAction = new QAction(QIcon(":/icons/icons/file-save.png"),tr("&Copy"),this);
    //copyAction->setIcon()
    copyAction->setShortcut(tr("Ctrl+C"));
    copyAction->setStatusTip(tr("Cut selection"));
    //connect(copyAction, SIGNAL(triggered()), this, SLOT(copy()));

    pasteAction = new QAction(QIcon(":/icons/icons/file-save.png"),tr("Paste"),this);
    //pasteAction->setIcon()
    pasteAction->setShortcut(tr("Ctrl+V"));
    pasteAction->setStatusTip(tr("Paste selection"));
    //connect(pasteAction, SIGNAL(triggered()), this, SLOT(paste()));

    fillSelectionAction = new QAction(QIcon(":/icons/icons/tool-bucket-fill-22.png"),tr("Fill Selection"),this);
    //fillSelectionAction->setIcon()
    fillSelectionAction->setShortcut(tr("Ctrl+I"));
    fillSelectionAction->setStatusTip(tr("Fill selection"));
    //connect(fillSelectionAction, SIGNAL(triggered()), this, SLOT(fillSelection()));

    blendToolAction = new QAction(tr("Blen&d Tool"),this);
    //blendToolAction->setIcon()
    blendToolAction->setShortcut(tr("Ctrl+D"));
    blendToolAction->setStatusTip(tr("Blend selection"));
    //connect(blendToolAction, SIGNAL(triggered()), this, SLOT(blendTool()));

    copyCurrLayerAction = new QAction(tr("&Copy Current Layer"),this);
    //copyCurrLayerAction->setIcon()
    copyCurrLayerAction->setShortcut(tr("Ctrl+Shift+C"));
    copyCurrLayerAction->setStatusTip(tr("Copy current layer"));
    //connect(copyCurrLayerAction, SIGNAL(triggered()), this, SLOT(copyCurrLayer()));

    resetParamAction = new QAction(tr("Reset &All Parameters"),this);
    //resetParamAction->setIcon()
    resetParamAction->setShortcut(tr("Ctrl+A"));
    resetParamAction->setStatusTip(tr("Reset all parameters"));
    //connect(resetParamAction, SIGNAL(triggered()), this, SLOT(resetParam()));

    cropInputAction = new QAction(tr("C&rop Input"),this);
    //cropInputAction->setIcon()
    cropInputAction->setShortcut(tr("Ctrl+R"));
    cropInputAction->setStatusTip(tr("Crop Input"));
    //connect(cropInputAction, SIGNAL(triggered()), this, SLOT(cropInput()));

    cropOutputAction = new QAction(tr("Crop Outpu&t"),this);
    //cropOutputAction->setIcon()
    cropOutputAction->setShortcut(tr("Ctrl+T"));
    cropOutputAction->setStatusTip(tr("Crop Output"));
    //connect(cropOutputAction, SIGNAL(triggered()), this, SLOT(cropOutput()));

    //view menu
    zoomInAction = new QAction(QIcon(":/icons/icons/view-zoomin.png"),tr("Zoom In"),this);
    zoomInAction->setIcon(QIcon(":/file-load.png"));
    zoomInAction->setShortcut(tr("Ctrl+="));
    zoomInAction->setStatusTip(tr("Zoom In"));
    //connect(zoomInAction, SIGNAL(triggered()), this, SLOT(zoomIn()));

    zoomOutAction = new QAction(QIcon(":/icons/icons/view-zoomout.png"),tr("Zoom Out"),this);
    //zoomOutAction->setIcon()
    zoomOutAction->setShortcut(tr("Ctrl+-"));
    zoomOutAction->setStatusTip(tr("Zoom Out"));
    //connect(zoomOutAction, SIGNAL(triggered()), this, SLOT(zoomOut()));

    fitWindowAction = new QAction(QIcon(":/icons/icons/file-save.png"),tr("Fit Window"),this);
    //fitWindowAction->setIcon()
    fitWindowAction->setShortcut(tr("Ctrl+W"));
    fitWindowAction->setStatusTip(tr("Fit Window"));
    //connect(fitWindowAction, SIGNAL(triggered()), this, SLOT(fitWindow()));

    fullscreenAction = new QAction(tr("&Fullscreen"),this);
    //fullscreenAction->setIcon()
    fullscreenAction->setShortcut(tr("Ctrl+F"));
    fullscreenAction->setStatusTip(tr("Set to fullscreen view"));
    //connect(fullscreenAction, SIGNAL(triggered()), this, SLOT(zfullscreen()));

    toggleAction = new QAction(tr("Toggle Sections"),this);
    //zoomInAction->setIcon()
    toggleAction->setShortcut(tr("Ctrl+B"));
    toggleAction->setStatusTip(tr("Toggle Section"));
    //connect(toggleInAction, SIGNAL(triggered()), this, SLOT(toggle()));

    layerMngrAction = new QAction(QIcon(":/icons/icons/view-layer-manager.png"),tr("Show Layer &Manager"),this);
    //layerMngrAction->setIcon()
    layerMngrAction->setShortcut(tr("Ctrl+M"));
    layerMngrAction->setStatusTip(tr("Show Layer Manager"));
    //connect(layerMngrAction, SIGNAL(triggered()), this, SLOT(layerMngr()));

    inputAction = new QAction(tr("Input"),this);
    //inputAction->setIcon()
    inputAction->setShortcut(tr("1"));
    inputAction->setStatusTip(tr("Input"));
    //connect(inputAction, SIGNAL(triggered()), this, SLOT(input()));

    outputAction = new QAction(tr("Output"),this);
    //outputAction->setIcon()
    outputAction->setShortcut(tr("2"));
    outputAction->setStatusTip(tr("Output"));
    //connect(outputAction, SIGNAL(triggered()), this, SLOT(output()));

    paletteAction = new QAction(tr("Palette"),this);
    //paletteAction->setIcon()
    paletteAction->setShortcut(tr("3"));
    outputAction->setStatusTip(tr("Palette"));
    //connect(paletteAction, SIGNAL(triggered()), this, SLOT(palette()));

    infoAction = new QAction(tr("Info"),this);
    //infoAction->setIcon()
    infoAction->setShortcut(tr("4"));
    infoAction->setStatusTip(tr("Info"));
    //connect(infoAction, SIGNAL(triggered()), this, SLOT(info()));
}


/*
 *createToolBoxsettings = new QtoolBox(this)
 *inputSetttings = new Qwidget()
 *mosaicSize = new QWidget()
 *mosaizRendering = new QWidget;
 *tilePallette = new QWidget();
 *grout = new QWiget);
 *
 *settings->additems(inputSetting, tr())
 *setting->addItem(mosaicSize)
 *settings->setGeometry
 *
 *
 *main.h
 *s_ for slot functions public
 *actionsMenu--make m_action for private actions variable
 *
 *
 *main.cpp
 *initialize everything in the constructor signature and initialize to NULL
 *Actions/Menus/Widgets (combine menu and toolbar)
 *setWIndowTitle("Tessear") in constructor.
 *slot functions always begin with s_
 *
 *3 spaces between functions
 *return type on seperate line in function
 *
 *
 *
 *
 *
 *
 */

