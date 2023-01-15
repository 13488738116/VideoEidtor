#ifndef VIDEOSLIDE_H
#define VIDEOSLIDE_H
#include"global.h"
#include <QLabel>
#include<QPainter>
//视频滑块
class VideoSlide : public QLabel
{
public:
    VideoSlide(int startTime, int duration,QString filename,QWidget*parent=nullptr);
    int m_startTime;//视频轴上的起始时间
    int m_endTime;//视频轴上的终止时间
    int m_duration()const{return m_endTime-m_startTime;}
    int m_startx()const{return (m_startTime*SIZE_PER_MIN)/60000;}//视频轴上的起始位置
    int m_endx()const{return (m_endTime*SIZE_PER_MIN)/60000;}//视频轴上的终止位置
    int m_length()const{return (m_duration()*SIZE_PER_MIN)/60000;}//视频轴上的长度
    int TimeToPos(int x){return (x*SIZE_PER_MIN)/60000;}//时间和位置的转化函数
    int PosToTime(int x){return (x*60000)/SIZE_PER_MIN;}

    QString filename;
    int StartOfVideo;//视频中的开始和结束位置，方便后期导出视频或是在预览区预览
    int EndOfVideo;//结束位置
    QString name()const{QStringList sections=filename.split('/');QString name=sections.value(sections.length()-1);return name;}
    void ResetTime(int position)//更新时间
    {
        int duration=m_duration();
        m_startTime=PosToTime(position);
        m_endTime=m_startTime+duration;
    }
    void RazorReset(int position)//用剃刀以后更新时间
    {
        m_endTime=(position-m_startx())*60000/SIZE_PER_MIN+m_startTime;
        EndOfVideo=m_duration()+StartOfVideo;
        setText(name());
        resize(m_length(),100);
        show();
    }
    //剪辑事件发生后更新相应信息
    void CutReset(int startpos,int endpos,int slotindex)
    {
        int x=(startpos-m_startx())*60000/SIZE_PER_MIN;
        int y=(m_endx()-endpos)*60000/SIZE_PER_MIN;
        m_startTime=m_startTime+x;
        m_endTime=m_endTime-y;
        StartOfVideo=StartOfVideo+x;
        EndOfVideo=EndOfVideo-y;
        resize(m_length(),100);
        setText(name());
        move(m_startx(),(slotindex-1)*100);
        show();
    }

};

#endif // VIDEOSLIDE_H
