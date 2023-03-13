#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QToolBar>
#include <QShortcut>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton_validate->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_B));
    //ui->toolButton->setStyleSheet("border:1px solid;");
    //ui->toolButton->setStyleSheet("qproperty-icon: url(./icon/redo.png);");

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_validate_clicked()
{
    int radius =  ui->lineEdit_parameter1->displayText().toInt();
    int height =  ui->lineEdit_parameter2->displayText().toInt();
    QGraphicsScene *scene = new QGraphicsScene();

    if (ui->comboBox_model->currentText()=="U"){
        scene->addEllipse(0,height-radius/4,radius,radius/2,QColorConstants::DarkBlue,QColorConstants::Blue);
        scene->addRect(0,0,radius,height,QColorConstants::DarkBlue,QColorConstants::Blue);
        scene->addEllipse(0,-radius/4,radius,radius/2,QColorConstants::DarkBlue,QColorConstants::LightGray);
        scene->addEllipse(0,height-radius/4,radius-2,radius/2-2,QColorConstants::Blue,QColorConstants::Blue);
    }
    else if (ui->comboBox_model->currentText()=="B"){
        scene->addEllipse(height-radius/4,0,radius/2,radius,QColorConstants::DarkBlue,QColorConstants::Blue);
        scene->addRect(0,0,height,radius,QColorConstants::DarkBlue,QColorConstants::Blue);
        scene->addEllipse(-radius/4,0,radius/2,radius,QColorConstants::DarkBlue,QColorConstants::LightGray);
        scene->addEllipse(height-radius/4,0,radius/2-2,radius-2,QColorConstants::Blue,QColorConstants::Blue);
    }
    else
    {
        scene->addRect(0,0,radius,height,QColorConstants::DarkBlue,QColorConstants::Blue);
    }
    ui->graphicsView->setScene(scene);
}

