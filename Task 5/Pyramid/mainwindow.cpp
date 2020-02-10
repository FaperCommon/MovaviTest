#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->comboBox->setCurrentIndex(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_OpenBut_clicked(){
    QList<QString> paths =(QFileDialog::getOpenFileNames(this,  tr("Open images"), "", tr("*.png *.jpg")));
    if(!paths.empty()){
       load_pics(paths);
       set_image(BuildPyramid(pic_s[0], ui->CB_layer_num->currentIndex()));
    }
}

void MainWindow::set_image(pic_file pic_s){
    ui->Label_size->setText(QString::number(pic_s.pic.size().width()) + 'x' + QString::number(pic_s.pic.size().height()));
    pic_s.pic = pic_s.pic.scaled(pic_s.pic_size, Qt::KeepAspectRatioByExpanding);
    scene = new QGraphicsScene();
    scene->addPixmap(pic_s.pic);
    ui->PicView->setScene(scene);
}


pic_file MainWindow::BuildPyramid(pic_file pic_s, int pow){
            int koef_com = 2;                       
             for(int i = 0;i < pow; i++)
                  pic_s.pic = pic_s.pic.scaled((pic_s.pic.size()/=koef_com), Qt::KeepAspectRatioByExpanding);
    return pic_s;
}


void MainWindow::on_CB_layer_num_activated(int index){
    if(!pic_s.empty())
        set_image(BuildPyramid(pic_s[ui->comboBox->currentIndex()],index)); //0
}

void MainWindow::load_pics(QList<QString> paths){
    pic_file adding;
    pic_s.clear();
    for(int i = 0; i < paths.size();i++){
       adding.pic.load(paths[i]);
       adding.pic_size = adding.pic.size();
       adding.path = paths[i];
       pic_s.push_back(adding);
    }
    sort();
    load_in_cb();
}

void MainWindow::on_comboBox_activated(int index){
    if(!pic_s.empty())
        set_image(BuildPyramid(pic_s[index],ui->CB_layer_num->currentIndex())); //0
}

void MainWindow::sort(){
        int leftMark = 1;
        int rightMark = pic_s.size() - 1;

         while (leftMark <= rightMark){
            for(int i = rightMark; i >= leftMark; i--){
                if (find_diagonal(pic_s[i-1].pic_size.width(),pic_s[i-1].pic_size.height()) > find_diagonal(pic_s[i].pic_size.width(),pic_s[i].pic_size.height()))
                    std::swap(pic_s[i-1],pic_s[i]);
            }
            leftMark++;
            for(int i = leftMark; i <= rightMark; i++){
                if (find_diagonal(pic_s[i-1].pic_size.width(),pic_s[i-1].pic_size.height()) > find_diagonal(pic_s[i].pic_size.width(),pic_s[i].pic_size.height()))
                    std::swap(pic_s[i-1],pic_s[i]);
            }
            rightMark--;
        }
}

float MainWindow::find_diagonal(int w, int h)
{
        return std::sqrt(std::pow(w,2)+std::pow(h,2));
}

void MainWindow::load_in_cb(){
    ui->comboBox->clear();
    for(size_t i = 0;i < pic_s.size();i++){
        ui->comboBox->addItem(pic_s[i].path.mid(pic_s[i].path.lastIndexOf("/")));
    }
}
