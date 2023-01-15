#ifndef MATERIALLIBRARY_H
#define MATERIALLIBRARY_H

#include<vector>
#include"global.h"
#include"rename.h"
#include <QWidget>
#include<QImage>
#include<QFileDialog>
#include<QMediaPlayer>
#include<QVideoProbe>
#include<QTextEdit>
#include<QListWidget>
#include<QDrag>
#include<QMimeData>
#include<QMouseEvent>
#include<QDataStream>
using namespace std;


namespace Ui {
class MaterialLibrary;
}
//素材库的界面
class MaterialLibrary : public QWidget
{
    Q_OBJECT

public:
    explicit MaterialLibrary(QWidget *parent = 0);
    ~MaterialLibrary();
    void CreateToolBar();//创建工具栏等内容
    void CreateImageList();//创建缩略图
    void ShiftImageList(int TypeOfImageList);//切换缩略图
    void AppendImageList(int TypeOfImageList,QString path);//为某缩略图增加内容
    int NumsOfVideo(QString filename);//给定一个视频获取其图片数量
    double FrameRateOfVideo(QString filename);//获取帧率
protected:
    void mousePressEvent(QMouseEvent *e);
private slots:
    void on_ImportIcon_triggered();
    void on_VideoMaterial_triggered();
    void on_PhotoMaterial_triggered();
    //处理素材点击事件
    void OnItemClicked(QListWidgetItem*item);
    void OnRename(QString newname);

    void on_Delete_triggered();

    void on_Rename_triggered();
    void OnRequest(int startoftime,int endoftime,QString filename);
signals:
    void VideoSelected(InfoOfVideo);
    void PhotoSelected(InfoOfPhoto);
    void FileRename(QString);
private:
    Ui::MaterialLibrary *ui;
    int m_TypeOfImageList;
    QListWidget** m_ImageList;
    int m_videoindex=0;
    int m_photoindex=0;//添加了多少照片
};

#endif // MATERIALLIBRARY_H
