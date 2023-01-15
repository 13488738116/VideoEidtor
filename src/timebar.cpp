#include "timebar.h"
#include <qpainter.h>
#include <QImage>
#include <QMouseEvent>
#include <QDebug>
#include <QPainter>
TimeBar::TimeBar(QWidget *parent) :
    QWidget(parent)

{
    m_start=10;
    m_maxMin=2;
    m_end=m_nMinuteWidth*m_maxMin+10;
}

TimeBar::~TimeBar()
{

}

void TimeBar::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setPen(QPen(QColor(0, 0, 0), 0));
    painter.setBrush(QBrush(QColor(0, 0, 0,0)));
    m_nMinuteWidth = (this->width()-150) / m_maxMin;		// 每小时单位长度
    int nY = 60;
    int nLongH = 20;
    int Margin = 10;

    //画分钟
    painter.setPen(QPen(QColor(0, 0, 0), 0));
    painter.setBrush(QBrush(QColor(0, 0, 0, 0)));
    int time = 0;
    for(int i = 0; i <m_maxMin; i++)
    {
        painter.drawLine(m_nMinuteWidth*i + Margin, nY, m_nMinuteWidth*i + Margin, nY - nLongH);
        for(int j=1;j<10;j++)
        {
            painter.drawLine(m_nMinuteWidth*i+(m_nMinuteWidth/10)*j + Margin, nY, m_nMinuteWidth*i+(m_nMinuteWidth/10)*j + Margin, nY - nLongH/2);
        }
        painter.drawText(m_nMinuteWidth*i - Margin, nY - nLongH, QString("00:%1:00").arg(QString::number(time)));
        time++;
    }
    painter.drawLine(m_nMinuteWidth*m_maxMin + Margin, nY, m_nMinuteWidth*m_maxMin + Margin, nY - nLongH);
    painter.drawText(m_nMinuteWidth*m_maxMin - Margin, nY - nLongH, QString("00:%1:00").arg(QString::number(time)));
    painter.drawLine(Margin,nY,m_nMinuteWidth*m_maxMin + Margin,nY);



    //画时间
    painter.setPen(QPen(QColor(0, 0, 0), 0));
    painter.drawText(m_xline + 10 , nY + 15, m_ShowCurrentTime);//画indicator下当前时间

    m_Line = QLine(m_xline + Margin,nY,m_xline + Margin ,300);//画indicator下边时间线
    painter.drawLine(m_Line);

    painter.setBrush(QBrush(QColor(0,0,255)));//画在时间轴上指示的indicator
    m_ImageMinuteRect = QRect(m_xline+Margin/2,nY-20,10,20);
    painter.drawRect(m_ImageMinuteRect);

}
void TimeBar::paintIndicator()
{
        int nY = 60;
        painter.setPen(QPen(QColor(0, 0, 0), 0));
        painter.drawText(m_xline + 10 , nY + 15, m_ShowCurrentTime);//画indicator下当前时间

        m_Line = QLine(m_xline + 10,nY,m_xline + 10 ,300);//画indicator下边时间线
        painter.drawLine(m_Line);

        painter.setBrush(QBrush(QColor(0,0,255)));
        m_ImageMinuteRect = QRect(m_xline,nY-20,10,20);
        painter.drawRect(m_ImageMinuteRect);

}
void TimeBar::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        if(event->pos().x() == m_xline + 5 && (event->pos().y() <= m_Line.y2() -m_Line.y1()))
        {
              m_IsClickedLine = true;
        }else if(m_ImageMinuteRect.contains(event->pos()))
        {
               m_IsClickedLine = true;
        }
        if(event->pos().x() >= 0 && event->pos().x()  <= m_nMinuteWidth * m_maxMin+10)
        {
                m_xline = event->pos().x();
                SignalSendXline(m_xline);
                setTime(m_xline);
        }
    }
    update();
}

void TimeBar::mouseMoveEvent(QMouseEvent * event)
{
    if (event->buttons() == Qt::LeftButton) //当满足鼠标左键被点击时。
    {
        if(m_bIsImageMinuteSelect == true){
            int x = event->pos().x();
            m_nTriangleMinuteX = x;
        }
        if(m_IsClickedLine == true){
            if(event->pos().x() >= 0 && event->pos().x()  <= m_nMinuteWidth * m_maxMin+10){
                    m_xline = event->pos().x();
                    SignalSendXline(m_xline);
                    setTime(m_xline);

            }
        }
    }
    update();
}
//根据位置设置当前时间
void TimeBar::setTime(double pos)
{
      TimePoint p;
      int second =  (pos) * 1800 / (m_nMinuteWidth * 30);
      p.hour = second /3600;
      p.minitue = (second % 3600) /60;
      p.second = second % 60;


        m_ShowCurrentTime = QString("%1").arg(p.hour, 2, 10, QLatin1Char('0'))
            + ":" + QString("%1").arg(p.minitue, 2, 10, QLatin1Char('0'))
                + ":" + QString("%1").arg(p.second, 2, 10, QLatin1Char('0'));
}



void TimeBar::SetProgress(int pos)
{
    if(m_IsClickedLine == true){//如果移动进度条的时候在播放，则进度条不在动
        return;
    }
    QString Progress = DateConcertion(pos);
    int midstatrhour = Progress.mid(0,2).toInt();
    int midstartmin = Progress.mid(3,2).toInt();
    int midstartsecond = Progress.mid(6,2).toInt();
    int starthour = midstatrhour * m_nMinuteWidth;
    int startmin = midstartmin * m_nMinuteWidth/ 60;
    int startsecond = midstartsecond*m_nMinuteWidth/3600;
    m_xline = starthour + startmin + startsecond;//时间线的位置
    m_ShowCurrentTime = QString("%1").arg(midstatrhour, 2, 10, QLatin1Char('0'))
            + ":" + QString("%1").arg(midstartmin, 2, 10, QLatin1Char('0'))
            + ":" + QString("%1").arg(midstartsecond, 2, 10, QLatin1Char('0'));
    update();
}

QString TimeBar::DateConcertion(int time)
{
    int second=time%60;
    int minute=time%3600/60;
    int hour=time % 86400 / 3600;
    QString time1;
    time1 = QString("%1").arg(hour, 2, 10, QLatin1Char('0'))
            + ":" + QString("%1").arg(minute, 2, 10, QLatin1Char('0'))
            + ":" + QString("%1").arg(second, 2, 10, QLatin1Char('0'));
    // qDebug() << time1;

    return  time1;
}

void TimeBar::mouseReleaseEvent(QMouseEvent *e)
{
    if(m_IsClickedLine == true)
    {


                for(int i = 0;i < m_painterdate.size();i++)
                {
                    if(e->pos().x() > m_painterdate.at(i).start && e->pos().x() < m_painterdate.at(i).end)
                    {
                        m_videoStartTime = m_ShowCurrentTime;
                        emit Signal_Senddate(m_videoStartTime);
                        break;
                    }

                }
    }
    m_IsClickedLine = false;
    m_bIsImageMinuteSelect = false;
}

void TimeBar::OnReceiveXline(double xline)
{
    m_xline=xline;
    setTime(xline);
    update();
}
