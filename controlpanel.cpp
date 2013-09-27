#include "ControlPanel.h"
#include "mainwindow.h"

ControlPanel::ControlPanel(QWidget *parent, QT::WIndowFlags f)
    :QWidget(parent, f)
{
    createMainTree();


}

void
ControlPanel::createPanelTree()
{
    m_tree = new QTreeWIdget;
    QVBOxLayout *vbox = new QVBoxLayout;


    m_tree->setHeaderTreeHidden(); //hide header
    m_tree->setColumnCOunt(1); //one column tree
    m_tree->setAnimated(true);
    m_tree->SetSelectionMode();
    m_tree->SetIndentation();
    m_tree->setFocusPOlicuy(Qt::NoFocus);
    m_tree->setFixedWidth();
    m-tree->setSizePolicy();


    vbox->addWidget(tree);
    setLayout(vbox);
    m_group.push_back(createGroupSize());
    m_group.push_back(create);
    m_group.push_back()


//push QWidgetItems to the QTree


}

QGroupBox*
createGroupInput()
{
    //create button items and labels and slider bars for all QTreeItems

//create brightness contrast
    QWidget *bcWidget = new QWidget;
    QGridLayout *grid = new QGridLayout;
    bcWidget->setLayout(grid);

    grid->addWidget(label[0],0,0);
    grid->addWIdget(m_sliderIn[0],0,1);
    grid->addWidget(m_buttonIn[0],0,2);
    groupBox->setLayout(grid);

    grid->addWidget(label[1],0,0);
    grid->addWIdget(m_sliderIn[1],0,1);
    grid->addWidget(m_buttonIn[1],0,2);
    groupBox->setLayout(grid);

    //better to use a for loop

    for(int i = 0; i<2;i++)
    {
        grid->addWidget(label[i], i, 0)
        grid->addWidget(label[0],0,0);
        grid->addWIdget(m_sliderIn[0],0,1);
        grid->addWidget(m_buttonIn[0],0,2);
        //groupBox->setLayout(grid);
    }

    //create radio butons
    m_radioIn[0] = new QRadioBUton("Brightness");
    m_radioIn[1] = new QRadioBUton("Contrast");

    hbox->addWidget(m_radioIn[0]);
    hbox->addWidget(m_radio[1]);

    QWidget *w = new QWidget;
    QHBoxLayout *hbox = new QHBoxLayout;

    w->setLayout();
    groupBox->setLayout(hbox); //for radio


    groupBox->setLayout(hbox);

    QStringList name;
    name << " Input Settings" //and the rest


//create widgets create layouts then create a
//input settings title is a button

}

QGroupBox*
createGroupInputSize()
{

}

QGroupBox*
createGroupInput()
{

}

QGroupBox*
create ()
{
}

QGroupBox*
create ()
{

}








