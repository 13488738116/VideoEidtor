#ifndef VIDEOPREVIEW_H
#define VIDEOPREVIEW_H

#include <QWidget>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QVideoFrame>
#include<QLabel>
#include<QToolButton>
#include<QHBoxLayout>
#include<QToolBar>
#include"myslider.h"
#include"global.h"


//预览框界面

namespace Ui {
class VideoPreview;
}

class VideoPreview : public QWidget
{
    Q_OBJECT
friend class TimeSegment;
public:
    explicit VideoPreview(QWidget *parent = 0);
    ~VideoPreview();
    void PlayByNum(QString filename,int startnum,int endnum);
public slots:
    void OnVideoSelected(InfoOfVideo info_video);
    void OnPhotoSelected(InfoOfPhoto info_Photo);
    void OnReceiveRequest(int current,int end);//接受视频轴中单击事件，改变进度条的范围
    void OnPreviewChange(int cum);//接受视频轴事件，改变进度条位置；

signals:
    void SubtitleImport();
public:
    Ui::VideoPreview *ui;
    MySlider* m_timeSlider;

    QMediaPlayer::State state;
    InfoOfVideo m_current;
    bool m_IsPause=false;//是否暂停
    bool m_IsTimebar=false;//是否收到时间轴的信号
    QImage m_image;
private slots:
    void on_PreviewIcon_triggered();
    void on_Subtitle_triggered();
};

#endif // VIDEOPREVIEW_H
