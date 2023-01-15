#include "subtitleslide.h"

SubtitleSlide::SubtitleSlide(InfoOfSubtitle subtitle,QWidget*parent):subtitle(subtitle),QLabel(parent)
{
    m_startTime=subtitle.startTime;
    m_endTime=subtitle.endTime;
    resize(TimeToPos(m_endTime-m_startTime),100);
    move(TimeToPos(m_startTime),300);
    setStyleSheet("QLabel{background-color:rgb(100,100,202);border:5px solid #242424;}");

}
