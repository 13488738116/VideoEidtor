#ifndef GLOBAL_H
#define GLOBAL_H
//定义视频和图片的类型
#define TYPE_VIDEO 0
#define TYPE_PHOTO 1
//定义时间轴长度和时间的换算关系
#define SIZE_PER_MIN 675
//定义图片特效
#define NULLEFFECT 0
#define ZOOM    1
#define TRANSLATION 2
#define FADEIN 3
#define FADEOUT 4




#include<QDrag>
#include<vector>
#include<QTime>
#include<QDebug>
#include<QString>
#include<QLabel>
#include<QProcess>
#include<QMediaPlayer>
#include<QCoreApplication>
#include<QGraphicsView>
using namespace std;

extern "C"
{
    #include <libavcodec/avcodec.h>
    #include <libavformat/avformat.h>
    #include <libswscale/swscale.h>
    #include <libavdevice/avdevice.h>
    #include <libavformat/version.h>
    #include <libavutil/time.h>
    #include <libavutil/mathematics.h>
    #include <libavutil/imgutils.h>
}


//存放视频、图片以及字幕信息的结构体

struct InfoOfVideo
{
   QString filename;
   int type=-1;
   double FrameRate=30;//帧率
   int Nums;//视频图片数量
   int Duration()const{return (Nums*1000)/FrameRate;}
   int StartnumByTime(int startofvideo)const{return (FrameRate*startofvideo)/1000;}//根据视频开始时间获取帧数
   int EndnumByTime(int endofvideo)const{return (FrameRate*endofvideo)/1000;}//根据视频结束时间获取帧数
};
struct InfoOfPhoto
{
  QString filename;
  double FrameRate=30;//图片帧率
  int Nums()const{return (Duration*FrameRate)/1000;}//图片播放数量
  int Duration;//播放时长，单位是ms
  int TypeOfEffect=NULLEFFECT;//特效类型
  double ZoomFac;//缩放比
  int posx;
  int posy;

};
struct InfoOfSubtitle
{
    QString text;
    int startTime;
    int endTime;
    int startNum()const{return (30*startTime)/1000;}//根据字幕开始时间获取帧数
    int endNum()const{return (30*endTime)/1000;}//根据字幕结束时间获取帧数
};
//全局储存图片、视频以及字幕的类
extern InfoOfPhoto*info_photo;
extern InfoOfVideo*info;
extern QDrag*drag;
extern vector<InfoOfSubtitle>InfoOfSubtitles;
extern vector<InfoOfVideo>InfoOfVideos;
extern vector<InfoOfPhoto>InfoOfPhotos;
//全局预览框播放视频的label
extern QLabel* g_PlayLabel;
extern QLabel* g_PhotoLabel;
extern QLabel* g_SubtitleLabel;
extern QGraphicsView* g_ScreenCut;
//延时函数
extern void delay(int msec);
#endif // GLOBAL_H
