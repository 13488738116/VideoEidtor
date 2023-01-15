#include "videoslide.h"
VideoSlide::VideoSlide(int startTime, int duration,QString filename,QWidget*parent):m_startTime(startTime),m_endTime(startTime+duration)
  ,filename(filename),QLabel(parent)
{
   double length=(double)(duration*SIZE_PER_MIN)/60000;
   resize(length,100);
   setText(name());
   setStyleSheet("QLabel{background-color:rgb(200,101,102);border:5px solid #242424;}");
}

