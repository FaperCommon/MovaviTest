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
       pic.load(path);
       set_image(BuildPyramid(pic, ui->CB_layer_num->currentIndex()));
    }


}

void MainWindow::set_image(QPixmap pic){
    ui->Label_size->setText(QString::number(pic.size().width()) + 'x' + QString::number(pic.size().height()));
    pic = pic.scaled(pic_size, Qt::KeepAspectRatioByExpanding);
    scene = new QGraphicsScene();
    scene->addPixmap(pic);
    ui->PicView->setScene(scene);
}


QPixmap MainWindow::BuildPyramid(QPixmap pic, int pow){
            int koef_com = 2;                       
            pic_size = pic.size();
             for(int i = 0;i < pow; i++)
                  pic = pic.scaled((pic.size()/=koef_com), Qt::KeepAspectRatioByExpanding);
    return pic;
}


void MainWindow::on_CB_layer_num_activated(int index)
{
    if(!pic.isNull())
        set_image(BuildPyramid(pic,index));
}
