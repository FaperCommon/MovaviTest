#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_OpenBut_clicked()
{
    QString path = QFileDialog::getOpenFileName(this,  tr("Open image"), "", tr("*.png *.jpg"));
    if(path != ""){
        scene = new QGraphicsScene();
        scene->addPixmap(path);
        ui->PicView->setScene(scene);
    }
}
