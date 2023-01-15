#ifndef TIMESEGMENT_H
#define TIMESEGMENT_H
#include"sequence.h"
#include"settingphoto.h"
#include"global.h"
#include <QWidget>
#include<QPainter>
#include<QMouseEvent>
#include<QGraphicsEffect>
namespace Ui {
class TimeSegment;
}
//TimeSegment类，是时间轴下边四个滑槽的总控件，在这个类里面处理滑块间移动、剪辑、切分等操作，根据不同槽类型实现相应的ui功能
class TimeSegment : public QWidget
{
    Q_OBJECT
    friend class VideoPreview;
public:
    explicit TimeSegment(QWidget *parent = 0);
    ~TimeSegment();

protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);
public slots:
    void OnReceiveXline(double xline);
    void OnReceiveRazor()//点击了razor按钮
    {
        m_IsRazored=true;
    }
    void OnReceiveCutStart()//点击了开始截取按钮
    {
        m_IsStartCutClicked=true;
    }
    void OnReceiveCutEnd()//点击了结束截取按钮
    {
        m_IsEndCutClicked=true;
    }
    void OnPhotoSet(double fac,int x,int y,int duration,int type);
    void OnSubtitleImport();
   signals:
        SignalSendXline(double);
        PreviewRequest(int,int);//请求在预览窗口显示当前时间轴内裁剪的视频
        LibraryRequest(int,int,QString);//请求在素材库中显示裁剪后的视频
        PreviewChange(int cnum);//进度条与时间轴同步
public:
    Ui::TimeSegment *ui;
    QLine m_Line;//播放进度条
    double m_xline = 0;//直线的X坐标
    Sequence*VideoPlay;//播放槽
    Sequence*VideoSequence2;//视频槽
    Sequence*VideoSequence3;
    Sequence*SubtitleSequence;//字幕槽
    Sequence*PhotoSequence;//图片槽

    bool SlideSelected;//标记是否可以执行拖动滑块的操作
    int m_Margin;//记录鼠标和label的相对位置
    int m_index;//记录滑槽索引
    int m_NumOfSlot;//记录位于第几个滑槽；
    int m_TimeEnd()const//记录时间轴剪辑视频的结束时间
    {
        if(VideoPlay->Videos.size()==0)
        {
            return 0;
        }
        else
        {
            return VideoPlay->Videos[VideoPlay->Videos.size()-1]->m_endTime;
        }
    }
    int m_currentTime(){return PosToTime(m_xline);}
    int TimeToPos(int x){return (x*SIZE_PER_MIN)/60000;}
    int PosToTime(int x){return (x*60000)/SIZE_PER_MIN;}
    bool m_IsRazored=false;//标记是否选中了切分视频功能
    bool m_IsRazorExe;//标记是否执行了切分视频的功能
    void RazorVideo(int Slot, int index, int position);//切分视频
    void CutVideo(int Slot,VideoSlide*slide,int spos,int epos,int count);//剪辑视频
    bool m_IsStartCutClicked=false;//开始截取按钮是否按下
    bool m_IsEndCutClicked=false;
    bool m_IsCutExe=false;
    int m_Cindex;//截取目标的序号
    int m_Cslot;//截取目标的槽
    int m_CSposition;//截取目标开始位置
    int m_totalframe;//剪辑后总帧数
    double m_step;//步长
    int m_Cnum;//当前帧数
    bool m_IsPreviewed=true;
    int m_timecount=0;//计数器

    void PlayClippedVideo(int xline);
    void PlayByNum(QString filename, int startnum, int endnum);

    int m_pos;//鼠标点击位置的x坐标
    int m_currentPhotoindex=-1;
    void SetPhotoOn();
    void SetSubtitleOn();

};

#endif // TIMESEGMENT_H
