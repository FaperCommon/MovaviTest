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

private:
    QGraphicsScene *scene;
    Ui::MainWindow *ui;
    void set_image(QString path);
    void set_image(QPixmap pic);
    void BuildPyramid(QString path);
};

#endif // MAINWINDOW_H
