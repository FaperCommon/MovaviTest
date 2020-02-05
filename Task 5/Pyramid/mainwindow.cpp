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
       QPixmap pic(path);
       BuildPyramid(path);
       //set_image(pic);
    }


}

void MainWindow::set_image(QPixmap pic){
   // scene = new QGraphicsScene();
    scene->addPixmap(pic);
    ui->PicView->setScene(scene);
}


void MainWindow::BuildPyramid(QString path){

            QPixmap pic(path);                                   //size for compression
            int koef_com = 2;
            // QSize size = pic.size();
             do{
                  set_image(pic);
                  pic = pic.scaled(pic.size()/=koef_com, Qt::KeepAspectRatioByExpanding);
             }while(pic.size().width() > 2 && pic.size().height() > 2);

}



