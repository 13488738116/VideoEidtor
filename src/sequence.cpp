#include "sequence.h"
#include<QFileInfo>
Sequence::Sequence(int Y,QWidget*parent):Y(Y),parent(parent)
{

}
//在轨道中添加相应的视频、字幕和图片滑块
void Sequence::SetVideoSlide(int startTime, qint64 duration,int startofvideo,int endofvideo, QString filename)
{

    VideoSlide* slide=new VideoSlide(startTime,duration,filename,parent);
    slide->StartOfVideo=startofvideo;
    slide->EndOfVideo=endofvideo;
    slide->move(TimeToPos(startTime),Y);
    slide->show();
    Videos.push_back(slide);
}

void Sequence::SetPhotoSlide(int startTime, qint64 duration, double zoomfac,int x,int y,int type, QString filename)
{

    PhotoSlide* slide=new PhotoSlide(startTime,duration,filename,x,y,zoomfac,type,parent);
    slide->move(TimeToPos(startTime),400);
    slide->show();
    Photos.push_back(slide);
}
void Sequence::SetSubtitles()
{
    for(int i=0;i<InfoOfSubtitles.size();i++)
    {
        SubtitleSlide*slide=new SubtitleSlide(InfoOfSubtitles[i],parent);
        slide->show();
        Subtitles.push_back(slide);
    }
}
//设置切分滑块的前一个滑块的大小和位置，更新相应信息
void Sequence::SetRazorSlide(int startposition,int startofvideo,qint64 duration,QString filename)
{

    VideoSlide* slide=new VideoSlide(PosToTime(startposition),duration,filename,parent);
    slide->StartOfVideo=startofvideo;
    slide->EndOfVideo=duration+startofvideo;
    slide->move(startposition,Y);
    slide->show();
    Videos.push_back(slide);
}
//判断滑块间是否有重叠
bool Sequence::IsOverlap(int position,int duration,int index)
{
    int length=(duration*SIZE_PER_MIN)/60000;
    for(int i=0;i<Videos.size();i++)
    {
        int end=Videos[i]->m_startx()+Videos[i]->m_length();
        if(i!=index)
        {
        if(position>=Videos[i]->m_startx()&&position<end)
        {
            return true;
        }
        else if(position<Videos[i]->m_startx()&&(position+length)>Videos[i]->m_startx())
        {
            return true;
        }
        }
    }
    return false;
}
//点击后根据位置判断是否有滑块，如果有的话返回滑块的索引值
int Sequence::IndexOfPhotoSlide(int position)
{
    for(int i=0;i<Photos.size();i++)
    {
        if(position>=Photos[i]->m_startx()&&position<=Photos[i]->m_startx()+Photos[i]->m_length())
        {

            return i;
        }
    }
    return -1;
}
int Sequence::IndexOfSlide(int position)
{
    for(int i=0;i<Videos.size();i++)
    {
        if(position>=Videos[i]->m_startx()&&position<=Videos[i]->m_startx()+Videos[i]->m_length())
        {

            return i;
        }
    }
    return -1;
}
