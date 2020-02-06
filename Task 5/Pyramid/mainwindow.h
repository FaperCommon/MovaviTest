#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QGraphicsView"
#include <QFileDialog>

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

private:
    QGraphicsScene *scene;
    Ui::MainWindow *ui;
    QPixmap pic;
    QSize pic_size;
    void set_image(QPixmap pic);
    QPixmap BuildPyramid(QPixmap pic,int pow);
};

#endif // MAINWINDOW_H
