#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QSplitter>
#include <QTextEdit>
#include <QSlider>
#include <QToolBar>
#include <QIcon>
#include <QDockWidget>
#include <QListWidget>
#include <QRadioButton>
#include <QGroupBox>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QTreeWidgetItem>
#include <QTreeWidget>

class QWidget;
class QTabWidget;
class QMenu;
class QAction;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow();

private:

    QRadioButton *radio1;
    QRadioButton *radio2;
    QRadioButton *radio3;

    QPushButton *button1;
    QPushButton *button2;
    QPushButton *button3;
    QPushButton *button4;
    QPushButton *button5;

    QGroupBox *groupBox1;
    QGroupBox *groupBox2;
    QGroupBox *groupBox3;
    QGroupBox *groupBox4;

    QVBoxLayout *layout;


    QSplitter *mainSplitter;

    QWidget *brMenu;
    QWidget *window;

    QSlider *brightSlide;
    QSlider *contSlide;

    QListWidget *listInDock;

    QRadioButton *bright;
    QRadioButton *contrast;

    QVBoxLayout *vbox;

    void createWidgets();
    void createMenus();
    void createActions();
    void createToolBars();
    void createDockWidget();

    QTabWidget *m_tabs;
    QTabWidget *m_tabs2;

    QWidget *m_input;
    QWidget *m_output;
    QWidget *m_palette;
    QWidget *m_info;

    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *viewMenu;

    QToolBar *fileToolBar;
    QToolBar *viewToolBar;

    QDockWidget *rightDock;

    QGridLayout *grid;

    QAction *newAction;
    QAction *openAction;
    QAction *loadAction;
    QAction *saveAction;
    QAction *saveAsAction;
    QAction *savePaletteAction;
    QAction *loadPaletteAction;
    QAction *exportAction;
    QAction *quitAction;
    QAction *undoAction;
    QAction *redoAction;
    QAction *cutAction;
    QAction *copyAction;
    QAction *pasteAction;
    QAction *fillSelectionAction;
    QAction *blendToolAction;
    QAction *copyCurrLayerAction;
    QAction *resetParamAction;
    QAction *cropInputAction;
    QAction *cropOutputAction;
    QAction *zoomInAction;
    QAction *zoomOutAction;
    QAction *fitWindowAction;
    QAction *fullscreenAction;
    QAction *toggleAction;
    QAction *layerMngrAction;
    QAction *inputAction;
    QAction *outputAction;
    QAction *paletteAction;
    QAction *infoAction;
};

#endif // MAINWINDOW_H

