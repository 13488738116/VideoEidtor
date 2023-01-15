#include"global.h"
InfoOfPhoto*info_photo;
InfoOfVideo*info;
QDrag*drag;
vector<InfoOfSubtitle>InfoOfSubtitles;
vector<InfoOfVideo>InfoOfVideos;
vector<InfoOfPhoto>InfoOfPhotos;
QLabel* g_PlayLabel;
QLabel* g_PhotoLabel;
QLabel* g_SubtitleLabel;
QGraphicsView* g_ScreenCut;
// 延时函数
void delay(int msec)
{
    QTime dieTime = QTime::currentTime().addMSecs(msec);
    while( QTime::currentTime() < dieTime )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
