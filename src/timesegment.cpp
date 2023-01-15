#include "timesegment.h"
#include "ui_timesegment.h"
#include<QDebug>
#include<QMediaplayer>
#include<QFileInfo>
#include<QMessageBox>
TimeSegment::TimeSegment(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TimeSegment)
{
    ui->setupUi(this);
    setAcceptDrops(true);
    ui->line->move(0,100);
    ui->line->resize(1350,2);
    ui->line_2->move(0,200);
    ui->line_2->resize(1350,2);
    ui->line_3->move(0,300);
    ui->line_3->resize(1350,2);
    ui->line_4->move(0,0);
    ui->line_4->resize(1350,2);
    ui->line_5->move(0,398);
    ui->line_5->resize(1350,2);
    ui->line_6->move(1350,0);
    ui->line_6->resize(2,500);
    ui->line_7->move(0,498);
    ui->line_7->resize(1350,2);
    VideoPlay=new Sequence(0,this);
    VideoSequence2=new Sequence(100,this);
    VideoSequence3=new Sequence(200,this);
    SubtitleSequence=new Sequence(300,this);
    PhotoSequence=new Sequence(400,this);

}

TimeSegment::~TimeSegment()
{
    delete ui;
}
//更新时间指示
void TimeSegment::OnReceiveXline(double xline)
{
    m_xline=xline;
    update();
}

void TimeSegment::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setPen(QPen(QColor(0, 0, 0), 0));
    painter.setBrush(QBrush(QColor(0, 0, 0,0)));
    m_Line = QLine(m_xline,0,m_xline ,500);//画indicator下边时间线
    painter.drawLine(m_Line);
}
//重写鼠标释放函数
void TimeSegment::mouseReleaseEvent(QMouseEvent * event)
{
        int offset=0;
        //对于视频播放槽，从其他槽中拖拽过来的滑块会直接从m_TimeEnd位置处开始添加，也就是说不同的视频间没有间隔，限制了用户一些操作，方便播放

        if(event->pos().y()>=0&&event->pos().y()<=100&&SlideSelected&&!m_IsRazorExe&&! m_IsCutExe)
        {



                    if(m_NumOfSlot==2)
                    {
                        VideoPlay->SetVideoSlide(m_TimeEnd(),VideoSequence2->Videos[m_index]->m_duration(),VideoSequence2->Videos[m_index]->StartOfVideo,VideoSequence2->Videos[m_index]->EndOfVideo,VideoSequence2->Videos[m_index]->filename);
                        VideoSequence2->Videos[m_index]->hide();
                        VideoSequence2->Videos.erase(VideoSequence2->Videos.begin()+m_index);
                    }
                    else if(m_NumOfSlot==3)
                    {
                        VideoPlay->SetVideoSlide(m_TimeEnd(),VideoSequence3->Videos[m_index]->m_duration(),VideoSequence3->Videos[m_index]->StartOfVideo,VideoSequence3->Videos[m_index]->EndOfVideo,VideoSequence3->Videos[m_index]->filename);
                        VideoSequence3->Videos[m_index]->hide();
                        VideoSequence3->Videos.erase(VideoSequence3->Videos.begin()+m_index);
                    }



        }
        //对于视频槽，可以接受来自任何槽的滑块，所以需要分情况判断
        else if(event->pos().y()>=100&&event->pos().y()<=200&&SlideSelected)
        {
                                    //如果来自本滑槽，那么之间当前的滑块move一段距离即可
                                    if(m_NumOfSlot==2&&!VideoSequence2->IsOverlap(event->pos().x()-m_Margin,VideoSequence2->Videos[m_index]->m_duration(),m_index)&&!m_IsRazorExe&&! m_IsCutExe)
                                    {
                                        VideoSequence2->Videos[m_index]->move(event->pos().x()-m_Margin+offset,VideoSequence2->Y);
                                        VideoSequence2->Videos[m_index]->ResetTime(event->pos().x()-m_Margin+offset);
                                    }
                                    //如果来自其他滑槽，则需要从其他滑槽中删除滑块并且在本滑槽中添加滑块
                                    else if(m_NumOfSlot==3&&!VideoSequence2->IsOverlap(event->pos().x()-m_Margin,VideoSequence3->Videos[m_index]->m_duration(),m_index)&&!m_IsRazorExe&&! m_IsCutExe)
                                    {
                                        VideoSequence2->SetVideoSlide(PosToTime(event->pos().x()+offset),VideoSequence3->Videos[m_index]->m_duration(),VideoSequence3->Videos[m_index]->StartOfVideo,VideoSequence3->Videos[m_index]->EndOfVideo,VideoSequence3->Videos[m_index]->filename);
                                        VideoSequence3->Videos[m_index]->hide();
                                        VideoSequence3->Videos.erase(VideoSequence3->Videos.begin()+m_index);
                                    }
                                    else if(m_NumOfSlot==1&&!VideoSequence2->IsOverlap(event->pos().x()-m_Margin,VideoPlay->Videos[m_index]->m_duration(),m_index))
                                    {
                                        VideoSequence2->SetVideoSlide(PosToTime(event->pos().x()+offset),VideoPlay->Videos[m_index]->m_duration(),VideoPlay->Videos[m_index]->StartOfVideo,VideoPlay->Videos[m_index]->EndOfVideo,VideoPlay->Videos[m_index]->filename);
                                        VideoPlay->Videos[m_index]->hide();
                                        VideoPlay->Videos.erase(VideoPlay->Videos.begin()+m_index);
                                    }

       }
        else if(event->pos().y()>=200&&event->pos().y()<=300&&SlideSelected)
        {


                    if(m_NumOfSlot==3&&!VideoSequence3->IsOverlap(event->pos().x()-m_Margin,VideoSequence3->Videos[m_index]->m_duration(),m_index)&&!m_IsRazorExe&&! m_IsCutExe)
                    {
                        VideoSequence3->Videos[m_index]->move(event->pos().x()-m_Margin+offset,VideoSequence3->Y);
                        VideoSequence3->Videos[m_index]->ResetTime(event->pos().x()-m_Margin+offset);
                    }
                    else if(m_NumOfSlot==2&&!VideoSequence3->IsOverlap(event->pos().x()-m_Margin,VideoSequence2->Videos[m_index]->m_duration(),m_index)&&!m_IsRazorExe&&! m_IsCutExe)
                    {
                        VideoSequence3->SetVideoSlide(PosToTime(event->pos().x()+offset),VideoSequence2->Videos[m_index]->m_duration(),VideoSequence2->Videos[m_index]->StartOfVideo,VideoSequence2->Videos[m_index]->EndOfVideo,VideoSequence2->Videos[m_index]->filename);
                        VideoSequence2->Videos[m_index]->hide();
                        VideoSequence2->Videos.erase(VideoSequence2->Videos.begin()+m_index);
                    }
                    else if(m_NumOfSlot==1&&!VideoSequence3->IsOverlap(event->pos().x()-m_Margin,VideoPlay->Videos[m_index]->m_duration(),m_index))
                    {
                        qDebug()<<"what";
                        VideoSequence3->SetVideoSlide(PosToTime(event->pos().x()+offset),VideoPlay->Videos[m_index]->m_duration(),VideoPlay->Videos[m_index]->StartOfVideo,VideoPlay->Videos[m_index]->EndOfVideo,VideoPlay->Videos[m_index]->filename);
                        VideoPlay->Videos[m_index]->hide();
                        VideoPlay->Videos.erase(VideoPlay->Videos.begin()+m_index);
                    }

        }
        //如果是图片滑槽，则也会限制用户使用权限，只能在该轨道内进行移动
        else if(event->pos().y()>=400&&event->pos().y()<=500&&SlideSelected&&(event->pos().x()-m_Margin+PhotoSequence->Photos[m_index]->m_length()<=TimeToPos(m_TimeEnd())))
        {

            PhotoSequence->Photos[m_index]->move(event->pos().x()-m_Margin+offset,400);
            PhotoSequence->Photos[m_index]->ResetTime(event->pos().x()-m_Margin+offset);
        }
    update();
}
void TimeSegment::dragEnterEvent(QDragEnterEvent *event)
{
    event->setDropAction(Qt::MoveAction);
    event->accept();
}
//拖拽时间，接受素材框中的素材拖拽到不同槽中
void TimeSegment::dropEvent(QDropEvent *event)
{
   if(info->type==TYPE_VIDEO)
   {
    if(event->pos().x()>=0&&event->pos().x()<=1360)//视频素材
    {
        if(event->pos().y()>=0&&event->pos().y()<=100)//如果鼠标拖到了相应的位置则在对于滑槽中添加滑块
        {
                VideoPlay->SetVideoSlide(m_TimeEnd(),info->Duration(),0,info->Duration(),info->filename);
        }
        else if(event->pos().y()>=100&&event->pos().y()<=200&&!VideoSequence2->IsOverlap(event->pos().x(),info->Duration(),-1))
        {
                VideoSequence2->SetVideoSlide(PosToTime(event->pos().x()),info->Duration(),0,info->Duration(),info->filename);
        }
        else if(event->pos().y()>=200&&event->pos().y()<=300&&!VideoSequence3->IsOverlap(event->pos().x(),info->Duration(),-1))
        {
                VideoSequence3->SetVideoSlide(PosToTime(event->pos().x()),info->Duration(),0,info->Duration(),info->filename);
        }

    }
 }
   else//图片素材
   {
        SettingPhoto* a=new SettingPhoto;
        connect(a,SIGNAL(PhotoSetting(double,int,int,int,int)),this,SLOT(OnPhotoSet(double,int,int,int,int)));
        m_pos=event->pos().x();
        a->show();
   }
}
//重写鼠标点击事件
void TimeSegment::mousePressEvent(QMouseEvent *event)
{
    static int count=0;
    if(event->button() == Qt::LeftButton){

        if(event->pos().x() >= 0 && event->pos().x()  <= 1350)
        {
                //如果鼠标点击的是第一个滑槽内，而且鼠标点中了滑块
                if(event->pos().y()>=0&&event->pos().y()<=100&&VideoPlay->IndexOfSlide(event->pos().x())!=-1)
                {
                    //设置一些参数，方便release事件时处理
                    m_NumOfSlot=1;
                    m_index=VideoPlay->IndexOfSlide(event->pos().x());
                    m_Margin=event->pos().x()-VideoPlay->Videos[m_index]->m_startx();
                    m_IsEndCutClicked=false;
                    m_IsRazored=false;
                    m_IsStartCutClicked=false;
                    m_IsRazorExe=true;
                    SlideSelected=false;
                    if(m_index==VideoPlay->Videos.size()-1)//当索引值等于最后一个滑块时才能点击，创造出栈的特点
                  {
                    SlideSelected=true;

                  }

                }
                //如果点击的是第二三个滑槽，而且鼠标点中了滑块
                else if(event->pos().y()>=100&&event->pos().y()<=200&&VideoSequence2->IndexOfSlide(event->pos().x())!=-1)
                {
                    m_NumOfSlot=2;
                    m_index=VideoSequence2->IndexOfSlide(event->pos().x());
                    m_Margin=event->pos().x()-VideoSequence2->Videos[m_index]->m_startx();

                    if(!m_IsRazored&&!m_IsStartCutClicked)//当前没有切分且剪辑
                    {
                        //qDebug()<<QString::number(VideoSequence2->Videos[m_index]->m_startTime)<<QString::number(VideoSequence2->Videos[m_index]->m_endTime)<<QString::number(VideoSequence2->Videos[m_index]->StartOfVideo)<<QString::number(VideoSequence2->Videos[m_index]->EndOfVideo);
                    SlideSelected=true;
                    m_IsCutExe=false;
                    m_IsRazorExe=false;
                    }
                    else if(m_IsRazored)//当前处于切分
                    {
                        count++;
                        int index=VideoSequence2->IndexOfSlide(event->pos().x());
                        int end=VideoSequence2->Videos[index]->m_endx();
                        QString filename=VideoSequence2->Videos[index]->filename;
                        RazorVideo(2,index,event->pos().x());
                        count++;
                        VideoSequence2->SetRazorSlide(event->pos().x(),PosToTime(event->pos().x()-VideoSequence2->Videos[index]->m_startx())+VideoSequence2->Videos[index]->StartOfVideo,PosToTime(end-event->pos().x()),filename);
                        m_IsRazored=false;
                        m_IsRazorExe=true;
                    }
                    else if(m_IsStartCutClicked)//当前开始截取按钮被点击
                    {
                        SignalSendXline(m_xline);
                         m_Cindex=VideoSequence2->IndexOfSlide(event->pos().x());
                         m_Cslot=2;
                         if(!m_IsEndCutClicked)
                         {
                           m_CSposition=event->pos().x();

                         }
                         if(m_IsEndCutClicked)//当前结束截取按钮被点击
                         {
                             int index=VideoSequence2->IndexOfSlide(event->pos().x());
                             if(index==m_Cindex&&m_Cslot==2&&event->pos().x()>m_CSposition)
                             {
                                 count++;
                                 CutVideo(2,VideoSequence2->Videos[index],m_CSposition,event->pos().x(),count);
                                 m_IsStartCutClicked=false;
                                 m_IsEndCutClicked=false;
                                 m_IsCutExe=true;
                                 emit LibraryRequest(VideoSequence2->Videos[index]->StartOfVideo,VideoSequence2->Videos[index]->EndOfVideo,VideoSequence2->Videos[index]->filename);
                             }
                             else
                             {
                                 m_IsStartCutClicked=false;
                                 m_IsEndCutClicked=false;
                             }
                         }
                    }

                }
                else if(event->pos().y()>=200&&event->pos().y()<=300&&VideoSequence3->IndexOfSlide(event->pos().x())!=-1)
                {
                    m_index=VideoSequence3->IndexOfSlide(event->pos().x());
                    m_Margin=event->pos().x()-VideoSequence3->Videos[m_index]->m_startx();
                    m_NumOfSlot=3;
                    if(!m_IsRazored&&!m_IsStartCutClicked)
                    {
                        //qDebug()<<QString::number(VideoSequence3->Videos[m_index]->m_startTime)<<QString::number(VideoSequence3->Videos[m_index]->m_endTime)<<QString::number(VideoSequence3->Videos[m_index]->StartOfVideo)<<QString::number(VideoSequence3->Videos[m_index]->EndOfVideo);
                        SlideSelected=true;
                        m_IsCutExe=false;
                        m_IsRazorExe=false;
                    }
                    else if(m_IsRazored)
                    {
                        int index=VideoSequence3->IndexOfSlide(event->pos().x());
                        int end=VideoSequence3->Videos[index]->m_endx();
                        QString filename=VideoSequence3->Videos[index]->filename;
                        RazorVideo(3,index,event->pos().x());
                        qDebug()<<QString::number(PosToTime(event->pos().x()-VideoSequence3->Videos[index]->m_startx())+VideoSequence3->Videos[index]->StartOfVideo);
                       VideoSequence3->SetRazorSlide(event->pos().x(),PosToTime(event->pos().x()-VideoSequence3->Videos[index]->m_startx())+VideoSequence3->Videos[index]->StartOfVideo,PosToTime(end-event->pos().x()),filename);
                        m_IsRazored=false;
                        m_IsRazorExe=true;
                    }
                    else if(m_IsStartCutClicked)
                    {
                        SignalSendXline(m_xline);
                         m_Cindex=VideoSequence3->IndexOfSlide(event->pos().x());
                         m_Cslot=3;
                         if(!m_IsEndCutClicked)
                         {
                           m_CSposition=event->pos().x();

                         }
                         if(m_IsEndCutClicked)
                         {
                             int index=VideoSequence3->IndexOfSlide(event->pos().x());
                             if(index==m_Cindex&&m_Cslot==3&&event->pos().x()>m_CSposition)
                             {
                                CutVideo(3,VideoSequence3->Videos[index],m_CSposition,event->pos().x(),count);
                                 m_IsStartCutClicked=false;
                                  m_IsCutExe=true;
                                  emit LibraryRequest(VideoSequence3->Videos[index]->StartOfVideo,VideoSequence3->Videos[index]->EndOfVideo,VideoSequence3->Videos[index]->filename);
                                 m_IsEndCutClicked=false;
                             }
                             else
                             {
                                 m_IsStartCutClicked=false;
                                 m_IsEndCutClicked=false;
                             }
                         }
                    }
                }
                //如果点击的是图片槽
                else if(event->pos().y()>=400&&event->pos().y()<=500&&PhotoSequence->IndexOfPhotoSlide(event->pos().x())!=-1)
                {
                    m_IsEndCutClicked=false;
                    m_IsRazored=false;
                    m_IsStartCutClicked=false;
                    m_IsRazorExe=true;
                    m_index=PhotoSequence->IndexOfPhotoSlide(event->pos().x());
                    m_Margin=event->pos().x()-PhotoSequence->Photos[m_index]->m_startx();
                    SlideSelected=true;
                }
                //如果是其他情况，则会调用播放视频函数，播放视频
                else
                {


                    m_index=-1;
                    SlideSelected=false;

                    m_IsEndCutClicked=false;
                    m_IsRazored=false;
                    m_IsStartCutClicked=false;
                    m_IsRazorExe=true;
                    if(m_IsPreviewed)
                    {
                        m_xline = event->pos().x();
                        m_timecount=0;
                        SignalSendXline(m_xline);
                        PlayClippedVideo(m_xline);
                    }

                }
        }
    }
    update();
}
//切分视频
void TimeSegment::RazorVideo(int Slot, int index, int position)
{

    if(Slot==2)
    {
       VideoSequence2->Videos[index]->RazorReset(position);
    }
    if(Slot==3)
    {
       VideoSequence3->Videos[index]->RazorReset(position);
    }
}
void TimeSegment::CutVideo(int Slot,VideoSlide *slide, int spos, int epos,int count)
{
    slide->CutReset(spos,epos,Slot);
}
//调用ffmpeg库进行视频播放，输入视频路径、起止帧数，播放视频
void TimeSegment::PlayByNum(QString filename, int startnum, int endnum)
{

        AVFormatContext *pFormatCtx; // 存储音视频封装格式中包含的信息
        int videoIndex = -1; // 视频帧索引，初始化为-1
        AVCodecContext *pCodecCtx; // 视频流编码结构
        AVCodec *pCodec; // 视频解码器
        AVFrame *pFrame, *pFrameRGB;
        unsigned char *out_buffer;
        AVPacket *packet;
        int ret, got_picture;
        struct SwsContext *img_convert_ctx; // 主要用于视频图像的转换

        const char* filepath =filename.toStdString().c_str(); // 当前目录为构建目录

        // 注册FFMpeg的库
        av_register_all();

        /*** （一）打开音视频流并获取音视频流信息 ***/
        // 初始化AVFormatContext
        pFormatCtx = avformat_alloc_context();
        // 打开音视频流
        if (avformat_open_input(&pFormatCtx, filepath, nullptr, nullptr) != 0)
        {
            printf("Couldn't open input stream.");
            return;
        }
        // 获取音视频流数据信息
        if (avformat_find_stream_info(pFormatCtx, nullptr) < 0)
        {
            printf("Couldn't find stream information.");
            return;
        }

        /*** （二）查找视频流位置以及查找并打开视频解码器 ***/
        // 查找视频流的起始索引位置（nb_streams表示视音频流的个数）
        for (int i = 0; i < (int)pFormatCtx->nb_streams; i++)
        {
            // 查找到视频流时退出循环
            if (pFormatCtx->streams[i]->codec->codec_type == AVMEDIA_TYPE_VIDEO) // 判断是否为视频流
            {
                videoIndex = i;
                break;
            }
        }
        if (videoIndex == -1)
        {
            printf("Didn't find a video stream.");
            return ;
        }
        // 查找视频解码器
        pCodecCtx = pFormatCtx->streams[videoIndex]->codec; // 获取视频流编码结构
        pCodec = avcodec_find_decoder(pCodecCtx->codec_id);
        if (pCodec == nullptr)
        {
            printf("Codec not found.");
            return ;
        }
        // 打开解码器
        if (avcodec_open2(pCodecCtx, pCodec, nullptr) < 0)
        {
            printf("Could not open codec.");
            return ;
        }
        // 打印视频信息
        printf("--------------- File Information ----------------");
        av_dump_format(pFormatCtx, 0, filepath, 0); // 此函数打印输入或输出的详细信息
        printf("-------------------------------------------------");

        /*** （三）视频解码的同时处理图片像素数据 ***/
        // 创建帧结构，此函数仅分配基本结构空间，图像数据空间需通过av_malloc分配
        pFrame = av_frame_alloc();
        pFrameRGB = av_frame_alloc();
        // 创建动态内存,创建存储图像数据的空间（av_image_get_buffer_size获取一帧图像需要的大小）
        out_buffer = (unsigned char *)av_malloc((size_t)av_image_get_buffer_size(AV_PIX_FMT_RGB32, pCodecCtx->width, pCodecCtx->height, 1));
        // 存储一帧像素数据缓冲区
        av_image_fill_arrays(pFrameRGB->data, pFrameRGB->linesize, out_buffer,
            AV_PIX_FMT_RGB32, pCodecCtx->width, pCodecCtx->height, 1);
        packet = (AVPacket *)av_malloc(sizeof(AVPacket));

        // 初始化img_convert_ctx结构
        img_convert_ctx = sws_getContext(pCodecCtx->width, pCodecCtx->height, pCodecCtx->pix_fmt,
            pCodecCtx->width, pCodecCtx->height, AV_PIX_FMT_RGB32, SWS_BICUBIC, nullptr, nullptr, nullptr);
        // av_read_frame读取一帧未解码的数据
        static int count=0;
        while (av_read_frame(pFormatCtx, packet) >= 0)
        {

            // 如果是视频数据

            if (packet->stream_index == videoIndex)
            {
                // 解码一帧视频数据
                ret = avcodec_decode_video2(pCodecCtx, pFrame, &got_picture, packet);
                if (ret < 0)
                {
                    printf("Decode Error.");
                    return ;
                }
                if (got_picture)
                {
                    count++;
                    if(count<=startnum||count>=endnum)
                        continue;



                    sws_scale(img_convert_ctx, (const unsigned char* const*)pFrame->data, pFrame->linesize, 0, pCodecCtx->height,
                                        pFrameRGB->data, pFrameRGB->linesize);
                    QImage img((uchar*)pFrameRGB->data[0],pCodecCtx->width,pCodecCtx->height,QImage::Format_RGB32);
                    g_PlayLabel->setPixmap(QPixmap::fromImage(img).scaled(g_PlayLabel->size(),Qt::KeepAspectRatio,Qt::SmoothTransformation)); // 在label上播放视频图片
                    SetPhotoOn();
                    SetSubtitleOn();
                    QImage out=g_ScreenCut->grab().toImage();
                    QFileInfo finfo("./VideoProcess.exe");
                    out.save(finfo.absolutePath()+"/temp/"+QString::number(m_timecount)+".jpeg","jpeg");
                    PreviewChange(m_Cnum+m_timecount);
                    if(m_timecount%10==0)
                    {
                         m_xline+=10*m_step;
                         update();
                    }
                    SignalSendXline(m_xline);
                    m_timecount++;
                    delay(30);
                }
            }
            av_free_packet(packet);
        }
        count = 0;

        /*** （四）最后要释放申请的内存空间 ***/
        sws_freeContext(img_convert_ctx); // 释放一个SwsContext
        av_frame_free(&pFrameRGB);
        av_frame_free(&pFrame);
        avcodec_close(pCodecCtx);
        avformat_close_input(&pFormatCtx);
}
//播放剪辑后的视频片段
void TimeSegment::PlayClippedVideo(int xline)
{
    int i=0,Cnum,sum=0;
    m_IsPreviewed=false;
    //通过遍历视频片段数组获取总帧数以及当前位置的帧数，从而更改预览框中进度条位置、范围以及时间指针移动的步长
    for(i=0;i<VideoPlay->Videos.size();i++)//遍历视频片段数组
    {
            InfoOfVideo info_video;
            for(int j=0;j<InfoOfVideos.size();j++)//根据视频片段在滑块中保存的路径名在视频vector中寻找
            {
                if(VideoPlay->Videos[i]->filename==InfoOfVideos[j].filename)
                {
                   info_video=InfoOfVideos[j];
                }
            }
            int startoftime=VideoPlay->Videos[i]->StartOfVideo;
            int endoftime=VideoPlay->Videos[i]->EndOfVideo;
            int Margin=endoftime-startoftime;
            if(PosToTime(xline)>=VideoPlay->Videos[i]->m_startTime&&PosToTime(xline)<=VideoPlay->Videos[i]->m_endTime)
            {
               int margin=PosToTime(xline)-VideoPlay->Videos[i]->m_startTime;
               Cnum=sum+info_video.StartnumByTime(margin);
            }
            sum+=info_video.StartnumByTime(Margin);
    }

    m_totalframe=sum;
    m_step=(double)(TimeToPos(m_TimeEnd()))/(double)sum;
    m_Cnum=Cnum;
    PreviewRequest(Cnum,sum);

    //播放视频环节
    for(i=0;i<VideoPlay->Videos.size();i++)//遍历视频片段数组
    {
        if(PosToTime(xline)>=VideoPlay->Videos[i]->m_startTime&&PosToTime(xline)<=VideoPlay->Videos[i]->m_endTime)
        {
            InfoOfVideo info_video;
            for(int j=0;j<InfoOfVideos.size();j++)//根据视频片段在滑块中保存的路径名在视频vector中寻找
            {
                if(VideoPlay->Videos[i]->filename==InfoOfVideos[j].filename)
                {
                   info_video=InfoOfVideos[j];
                }
            }
            int startoftime=VideoPlay->Videos[i]->StartOfVideo;
            int endoftime=VideoPlay->Videos[i]->EndOfVideo;
            int Margin=PosToTime(xline)-VideoPlay->Videos[i]->m_startTime;
            PlayByNum(info_video.filename,info_video.StartnumByTime(startoftime+Margin),info_video.EndnumByTime(endoftime));
            break;
        }

    }
    for(int j=i+1;j<VideoPlay->Videos.size();j++)//遍历视频片段数组
    {
        InfoOfVideo info_video;
        for(int k=0;k<InfoOfVideos.size();k++)//根据视频片段在滑块中保存的路径名在视频vector中寻找
        {
            if(VideoPlay->Videos[j]->filename==InfoOfVideos[k].filename)
            {
               info_video=InfoOfVideos[k];
            }
        }
        //根据滑块在视频中的起止时间来播放
        int startoftime=VideoPlay->Videos[j]->StartOfVideo;
        int endoftime=VideoPlay->Videos[j]->EndOfVideo;
        PlayByNum(info_video.filename,info_video.StartnumByTime(startoftime),info_video.EndnumByTime(endoftime));
    }
    m_IsPreviewed=true;
}
//通过对话框设置完图像的信息之后在图片滑槽内部加入一个图片滑块
void TimeSegment::OnPhotoSet(double fac,int x,int y,int duration,int type)
{
    PhotoSequence->SetPhotoSlide(PosToTime(m_pos),duration,fac,x,y,type,info_photo->filename);
}
//此函数在播放视频的函数中被调用，播放视频的函数每一帧都会被调用，所以此函数每一帧都会进行图像的处理和绘制
//传入的index是帧数，绘制在g_PhotoLabel上进行，g_PhotoLabel是在视频播放label上面的一个label
void TimeSegment::SetPhotoOn()
{
    int time=PosToTime(m_xline);
    bool isfind=false;
    static int count=0;
    for(int i=0;i<PhotoSequence->Photos.size();i++)//遍历图片素材数组
    {
        //如果图片素材的起止时间包含当前的时间
        if(time>=PhotoSequence->Photos[i]->m_startTime&&time<=PhotoSequence->Photos[i]->m_endTime)
        {
            isfind=true;
            QImage img(PhotoSequence->Photos[i]->filename);
            //根据不同类型的特效进行绘制
            if(PhotoSequence->Photos[i]->m_effect==NULLEFFECT)//空特效
            {
                g_PhotoLabel->resize(500*PhotoSequence->Photos[i]->m_zoomfactor,300*PhotoSequence->Photos[i]->m_zoomfactor);
                g_PhotoLabel->setPixmap(QPixmap::fromImage(img).scaled(QSize(500*PhotoSequence->Photos[i]->m_zoomfactor,300*PhotoSequence->Photos[i]->m_zoomfactor),Qt::KeepAspectRatio,Qt::SmoothTransformation));
                g_PhotoLabel->move(PhotoSequence->Photos[i]->m_posx,PhotoSequence->Photos[i]->m_posy);
            }
            else if(PhotoSequence->Photos[i]->m_effect==TRANSLATION)//平移特效
            {
                int num=(PhotoSequence->Photos[i]->m_endTime-PhotoSequence->Photos[i]->m_startTime)/40;
                int step=500/num;
                g_PhotoLabel->resize(500*PhotoSequence->Photos[i]->m_zoomfactor,300*PhotoSequence->Photos[i]->m_zoomfactor);
                g_PhotoLabel->setPixmap(QPixmap::fromImage(img).scaled(QSize(500*PhotoSequence->Photos[i]->m_zoomfactor,300*PhotoSequence->Photos[i]->m_zoomfactor),Qt::KeepAspectRatio,Qt::SmoothTransformation));
                g_PhotoLabel->move(step*count,PhotoSequence->Photos[i]->m_posy);
            }
            else if(PhotoSequence->Photos[i]->m_effect==ZOOM)//缩放特效
            {
                int num=(PhotoSequence->Photos[i]->m_endTime-PhotoSequence->Photos[i]->m_startTime)/40;
                g_PhotoLabel->resize((500*PhotoSequence->Photos[i]->m_zoomfactor)/num*count,(300*PhotoSequence->Photos[i]->m_zoomfactor)/num*count);
                g_PhotoLabel->setPixmap(QPixmap::fromImage(img).scaled(g_PhotoLabel->size(),Qt::KeepAspectRatio,Qt::SmoothTransformation));
                g_PhotoLabel->move(PhotoSequence->Photos[i]->m_posx,PhotoSequence->Photos[i]->m_posy);
            }
            else if(PhotoSequence->Photos[i]->m_effect==FADEOUT)//淡出
            {
                int num=(PhotoSequence->Photos[i]->m_endTime-PhotoSequence->Photos[i]->m_startTime)/40;
                double opacity=(double)count/(double)num*2;
                QGraphicsOpacityEffect*effect=new QGraphicsOpacityEffect;
                effect->setOpacity(opacity);
                g_PhotoLabel->resize(500*PhotoSequence->Photos[i]->m_zoomfactor,300*PhotoSequence->Photos[i]->m_zoomfactor);
                g_PhotoLabel->setPixmap(QPixmap::fromImage(img).scaled(QSize(500*PhotoSequence->Photos[i]->m_zoomfactor,300*PhotoSequence->Photos[i]->m_zoomfactor),Qt::KeepAspectRatio,Qt::SmoothTransformation));
                g_PhotoLabel->move(PhotoSequence->Photos[i]->m_posx,PhotoSequence->Photos[i]->m_posy);
                g_PhotoLabel->setGraphicsEffect(effect);
            }
            else if(PhotoSequence->Photos[i]->m_effect==FADEIN)//淡入
            {
                int num=(PhotoSequence->Photos[i]->m_endTime-PhotoSequence->Photos[i]->m_startTime)/40;
                double opacity=1-(double)count/(double)num;
                QGraphicsOpacityEffect*effect=new QGraphicsOpacityEffect;
                effect->setOpacity(opacity);
                g_PhotoLabel->resize(500*PhotoSequence->Photos[i]->m_zoomfactor,300*PhotoSequence->Photos[i]->m_zoomfactor);
                g_PhotoLabel->setPixmap(QPixmap::fromImage(img).scaled(QSize(500*PhotoSequence->Photos[i]->m_zoomfactor,300*PhotoSequence->Photos[i]->m_zoomfactor),Qt::KeepAspectRatio,Qt::SmoothTransformation));
                g_PhotoLabel->move(PhotoSequence->Photos[i]->m_posx,PhotoSequence->Photos[i]->m_posy);
                g_PhotoLabel->setGraphicsEffect(effect);
            }
            count++;
            g_PhotoLabel->show();
        }
    }
    if(isfind==false)
    {
        g_PhotoLabel->hide();
        count=0;
    }
}
//传入的index是帧数，绘制在g_SubtitleLabel上进行，g_SubtitleLabel是在视频播放label上面的一个label
void TimeSegment::SetSubtitleOn()
{
    int time=PosToTime(m_xline);
    bool isfind=false;
    for(int i=0;i<SubtitleSequence->Subtitles.size();i++)//遍历图片素材数组
    {
        //如果图片素材的起止时间包含当前的时间
        if(time>=SubtitleSequence->Subtitles[i]->m_startTime&&time<=SubtitleSequence->Subtitles[i]->m_endTime)
        {
            isfind=true;
            g_SubtitleLabel->resize(300,100);
            QFont ft;
            ft.setPointSize(12);
            g_SubtitleLabel->setFont(ft);
            QPalette pa;
            pa.setColor(QPalette::WindowText,Qt::white);
            g_SubtitleLabel->setPalette(pa);
            g_SubtitleLabel->setText(SubtitleSequence->Subtitles[i]->subtitle.text);
            qDebug()<<SubtitleSequence->Subtitles[i]->subtitle.text;
            g_SubtitleLabel->move(100,200);
            g_SubtitleLabel->show();
        }
    }
    if(isfind==false)
    {
        g_SubtitleLabel->hide();
    }
}
//字幕文件导入后在字幕槽中添加字幕
void TimeSegment::OnSubtitleImport()
{
    SubtitleSequence->SetSubtitles();
}
