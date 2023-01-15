#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"videopreview.h"
#include"materiallibrary.h"
#include"videoprocess.h"
#include <QMainWindow>
namespace Ui {
class MainWindow;
}
//主窗口类，拥有三个成员，分别是预览窗口、时间轴以及素材库
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();



private:
    Ui::MainWindow *ui;
    VideoPreview* Preview;
    MaterialLibrary*Library;
    VideoProcess* ProcessAera;
    void ConnectSignals();
};

#endif // MAINWINDOW_H
