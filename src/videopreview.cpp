#include "videopreview.h"
#include "ui_videopreview.h"
#include<QPainter>
#include<QFileDialog>
VideoPreview::VideoPreview(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VideoPreview)
{

    ui->setupUi(this);
    g_ScreenCut=new QGraphicsView(this);
    g_ScreenCut->resize(500,300);
    g_ScreenCut->move(125,20);
    g_PlayLabel=new QLabel(g_ScreenCut);
    g_PlayLabel->move(0,0);
    g_PlayLabel->resize(500,300);
    g_PhotoLabel=new QLabel(g_PlayLabel);
    g_PhotoLabel->resize(100,100);
    g_PhotoLabel->move(10,10);
    g_SubtitleLabel=new QLabel(g_PlayLabel);


    m_timeSlider=new MySlider(Qt::Horizontal,this);
    m_timeSlider->setMinimum(0);      // 设置滑动条的最小值
    m_timeSlider->setMaximum(0);   // 设置滑动条的最大值
    m_timeSlider->setEnabled(false);
    m_timeSlider->move(20,325);
    m_timeSlider->resize(623,20);
    m_timeSlider->show();


    //按下播放按钮，改变按钮的状态；因为视频的状态被player这个播放器不断获取,所以onPlayerStateChanged一直被调用，相应的图片也会改变
    connect(ui->PreviewIcon,SIGNAL(triggered()),this,SLOT(onPlay()));



    QToolBar*toolBar2=new QToolBar(this);
    toolBar2->move(275,360);
    toolBar2->resize(250,40);
    toolBar2->addAction(ui->PreviewIcon);
    toolBar2->addAction(ui->PreviousFrame);
    toolBar2->addAction(ui->NextFrame);
    toolBar2->addAction(ui->Subtitle);
    ui->PreviousFrame->setEnabled(true);
    ui->NextFrame->setEnabled(true);


}

VideoPreview::~VideoPreview()
{
    delete ui;
}



//接受到来自时间轴点击事件，更新进度条播放范围以及当前值
void VideoPreview::OnReceiveRequest(int current, int end)
{
    m_IsTimebar=true;
    m_timeSlider->setMaximum(end);
    m_timeSlider->setValue(current);
}
//根据时间轴帧数变化set相应的value
void VideoPreview::OnPreviewChange(int cnum)
{
    m_timeSlider->setValue(cnum);
}


//接受来自素材库缩略图的点击事件，播放原素材视频
void VideoPreview::OnVideoSelected(InfoOfVideo info_video)
{
        m_IsTimebar=false;
        m_current=info_video;
        m_timeSlider->setMaximum(info_video.Nums);
        m_timeSlider->setValue(0);
        ui->PreviewIcon->setIcon(QIcon(":/new/prefix1/sourse/VideoPlaying.png"));
        ui->PreviousFrame->setEnabled(false);
        ui->NextFrame->setEnabled(false);
        PlayByNum(info_video.filename,0,info_video.Nums);

}
//接受来自素材库缩略图的点击事件，播放原素材图片
void VideoPreview::OnPhotoSelected(InfoOfPhoto info_Photo)
{
      m_timeSlider->setMaximum(0);
      QImage img(info_Photo.filename);
      g_PlayLabel->setPixmap(QPixmap::fromImage(img).scaled(g_PlayLabel->size(),Qt::KeepAspectRatio,Qt::SmoothTransformation));
}
//根据起止帧数，播放指定视频
void VideoPreview::PlayByNum(QString filename, int startnum, int endnum)
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
        while (av_read_frame(pFormatCtx, packet) >= 0&&!m_IsPause&&!m_IsTimebar)
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
                    m_timeSlider->setValue(count);

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
//设置暂停按钮
void VideoPreview::on_PreviewIcon_triggered()
{
    if(m_IsPause==false)
    {
        m_IsPause=true;
        ui->PreviewIcon->setIcon(QIcon(":/new/prefix1/sourse/Preview.png"));
        ui->PreviousFrame->setEnabled(true);
        ui->NextFrame->setEnabled(true);

    }
    else
    {
        m_IsPause=false;
        ui->PreviewIcon->setIcon(QIcon(":/new/prefix1/sourse/VideoPlaying.png"));
        ui->PreviousFrame->setEnabled(false);
        ui->NextFrame->setEnabled(false);
        PlayByNum(m_current.filename,m_timeSlider->value(),m_current.Nums);
    }
}
//设置导入字幕的按钮
void VideoPreview::on_Subtitle_triggered()
{
    QString path =QFileDialog::getOpenFileName(this,tr("打开文件"),"./",tr("Subtitle Files(srt) (*.txt)"));
    QFile file(path);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug()<<"Can't open the file!"<<endl;
    }
    while(!file.atEnd())
    {
        QString index = file.readLine();
        QString time = file.readLine();
        QString text = file.readLine();
        QString temp = file.readLine();
        while(temp!="\n"&&temp!="")
        {
            text.append(temp);
            temp = file.readLine();
        }
        QStringList str=time.split("-->");
        InfoOfSubtitle subtitle;
        subtitle.text=text;
        QStringList str1=str[0].split(":");
        int hour=str1[0].toInt();
        int minute=str1[1].toInt();
        int second=str1[2].toInt();
        second+=minute*60+hour*3600;
        subtitle.startTime=second*1000;
        str1=str[1].split(":");
        hour=str1[0].toInt();
        minute=str1[1].toInt();
        second=str1[2].toInt();
        second+=minute*60+hour*3600;
        subtitle.endTime=second*1000;
        InfoOfSubtitles.push_back(subtitle);
    }
    emit SubtitleImport();
}
