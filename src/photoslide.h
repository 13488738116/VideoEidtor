#ifndef PHOTOSLIDE_H
#define PHOTOSLIDE_H

#include <QObject>

#include"global.h"
#include <QLabel>
#include<QPainter>
//处理图片滑块，继承自QLabel类
class PhotoSlide : public QLabel
{
public:
    PhotoSlide(int startTime, int duration,QString filename,int x,int y,double zoom,int type,QWidget*parent=nullptr);
    int m_startTime;//视频轴上的起始时间
    int m_endTime;//视频轴上的终止时间
    int m_duration()const{return m_endTime-m_startTime;}
    int m_startx()const{return (m_startTime*SIZE_PER_MIN)/60000;}//视频轴上的起始位置
    int m_endx()const{return (m_endTime*SIZE_PER_MIN)/60000;}//视频轴上的终止位置
    int m_length()const{return (m_duration()*SIZE_PER_MIN)/60000;}//视频轴上的长度
    int TimeToPos(int x){return (x*SIZE_PER_MIN)/60000;}//时间和位置的转化函数
    int PosToTime(int x){return (x*60000)/SIZE_PER_MIN;}

    QString filename;
    QString name()const{QStringList sections=filename.split('/');QString name=sections.value(sections.length()-1);return name;}
   //记录图片的空间位置、大小、特效类型
    int m_posx;
    int m_posy;
    double m_zoomfactor;
    int m_effect;

    void ResetTime(int position)//更新时间
    {
        int duration=m_duration();
        m_startTime=PosToTime(position);
        m_endTime=m_startTime+duration;
    }
};

#endif // PHOTOSLIDE_H
