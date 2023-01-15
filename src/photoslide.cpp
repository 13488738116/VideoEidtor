#include "photoslide.h"

PhotoSlide::PhotoSlide(int startTime, int duration,QString filename,int x,int y,double zoom,int type,QWidget*parent):m_startTime(startTime),m_endTime(startTime+duration)
  ,filename(filename),m_posx(x),m_posy(y),m_zoomfactor(zoom),m_effect(type),QLabel(parent)
{
   double length=(double)(duration*SIZE_PER_MIN)/60000;
   resize(length,100);
   setText(name());
   setStyleSheet("QLabel{background-color:rgb(100,200,102);border:5px solid #242424;}");
}
