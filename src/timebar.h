#ifndef TIMEBAR_H
#define TIMEBAR_H
#include"videoprocess.h"
#include"global.h"
#include<QPainter>
#include<QLabel>
#include <QWidget>
#include <QMap>
namespace Ui {
class TimeBar;
}

//TimeBar类绘制时间轴的刻度线，并且维护时间indicator的滑动、点击响应
struct st_playbackdate
{
    int type; // 进度条颜色类型
    int start;
    int end;
};


class TimeBar : public QWidget
{
    Q_OBJECT
public:
    explicit TimeBar(QWidget *parent = nullptr);
    ~TimeBar();
    int m_nMinuteWidth;
    int m_nTriangleMinuteX = 0;
    QRect m_ImageMinuteRect; //分钟三角形的坐标

    QString m_ShowCurrentTime = "00:00:00"; //显示当前时间
    bool m_bIsImageMinuteSelect = false;
    bool m_IsClickedLine = false;//点击时间线
    void setTime(double);//设置拖动轴旁的时间
    void paintIndicator();


    int m_nStartMinute = 0;	//分钟开始的位置
    int m_nEndMinute = 0;	// 分钟结束的位置
    QString m_videoStartTime;//记录在时间段中拖动的最后时间信息，若时间线拖到没有录像的位置，则自动跳回
    QList<st_playbackdate>m_painterdate;//存储解析出来的
    void SetProgress(int pos);

private:
    Ui::TimeBar *ui;
    QLine m_Line; //播放进度条
    double m_xline = 0;//直线的X坐标
    int m_start;
    int m_end;
    int m_maxMin;//支持的最多分钟数
    QString DateConcertion(int);
    QPainter painter;

protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent * event);
    void mouseReleaseEvent(QMouseEvent *e);
public slots:
    void OnReceiveXline(double xline);
signals:
    Signal_Senddate(QString);
    SignalSendXline(int);
};

#endif // TIMEBAR_H
