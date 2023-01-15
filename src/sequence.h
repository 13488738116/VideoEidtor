#ifndef SEQUENCE_H
#define SEQUENCE_H
#include"videoslide.h"
#include"photoslide.h"
#include"subtitleslide.h"
#include"global.h"
#include<QLabel>
#include<QWidget>
#include<vector>
using namespace std;
//Sequence类是时间轴下边视频处理窗口的一个部件，用于管理视频槽的视频滑块，本身并不是Qt的类
class Sequence
{
public:
    Sequence(int Y, QWidget*parent);
    vector<VideoSlide*>Videos;
    vector<PhotoSlide*>Photos;
    vector<SubtitleSlide*>Subtitles;
    //为视频槽创建一个视频滑块并显示
    void SetVideoSlide(int startTime, qint64 duration,int startofvideo,int endofvideo, QString filename);
    //为视频创建一个图片滑块并显示
    void SetPhotoSlide(int startTime, qint64 duration, double zoomfac,int x,int y,int type, QString filename);
    //创建字幕滑块并显示
    void SetSubtitles();
    //使用裁刀后创建右边的滑块
    void SetRazorSlide(int startposition,int startofvideo,qint64 duration,QString filename);
    //判断拖拽过来的视频滑块是否和视频槽内已有的视频滑块冲突，默认情况下不允许视频滑块冲突
    bool IsOverlap(int position,int duration,int index);
    //判断鼠标当前所点击的位置是否有视频块,如果没有，则返回-1，有的话返回该视频块在sequence中数组的索引值
    int IndexOfSlide(int position);
    //判断鼠标当前是否有图片滑块，如果没有则返回-1，有的话则返回索引值
    int IndexOfPhotoSlide(int position);
    int Y;
private:
    QWidget*parent;
    int TimeToPos(int x){return (x*SIZE_PER_MIN)/60000;}
    int PosToTime(int x){return (x*60000)/SIZE_PER_MIN;}

};

#endif // SEQUENCE_H
