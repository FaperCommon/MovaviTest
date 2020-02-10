#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QGraphicsView"
#include <QFileDialog>
#include <QMessageBox>
#include <vector>
struct pic_file{
    QPixmap pic;
    QSize pic_size;
    QString path;
};
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_OpenBut_clicked();
    void on_CB_layer_num_activated(int index);



    void on_comboBox_activated(int index);

private:
    QGraphicsScene *scene;
    Ui::MainWindow *ui;
    std::vector<pic_file> pic_s;
    void set_image(pic_file pic_s);
    pic_file BuildPyramid(pic_file pic_s,int pow);
    void load_pics(QList<QString> paths);
    void sort();
    float find_diagonal(int w, int h);
    void load_in_cb();
};

#endif // MAINWINDOW_H
