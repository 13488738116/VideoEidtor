#include "materiallibrary.h"
#include "ui_materiallibrary.h"

MaterialLibrary::MaterialLibrary(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MaterialLibrary)
{
    ui->setupUi(this);
    m_TypeOfImageList=TYPE_VIDEO;
    info=new InfoOfVideo;
    info_photo=new InfoOfPhoto;
    CreateToolBar();
    CreateImageList();
    ShiftImageList(TYPE_VIDEO);
}

MaterialLibrary::~MaterialLibrary()
{
    delete ui;
}

void MaterialLibrary::OnRequest(int startoftime, int endoftime, QString filename)
{
    //设置单元项的名字
    QStringList sections = filename.split("/");
    QString name=sections.value(sections.length()-1);
    //定义QListWidgetItem对象
    QListWidgetItem *imageItem = new QListWidgetItem;
     imageItem->setText(name);
     //重新设置单元项图片的宽度和高度
     imageItem->setSizeHint(QSize(100,120));
     //为item储存一些必要的信息
     imageItem->setData(Qt::UserRole+1,0);
     imageItem->setData(Qt::UserRole,filename);
     imageItem->setFlags(imageItem->flags() & ~Qt::ItemIsEnabled & ~Qt::ItemIsSelectable);
     //将单元项添加到QListWidget中
     m_ImageList[0]->addItem(imageItem);
}
//创建视频和图片两个缩略图
void MaterialLibrary::CreateImageList()
{
    m_ImageList= (QListWidget**)malloc(2*sizeof(QListWidget*));
    for(int i=0;i<2;i++)
    {
        m_ImageList[i]=new QListWidget(this);
        m_ImageList[i]->resize(700,300);
        m_ImageList[i]->move(50,90);
        m_ImageList[i]->setIconSize(QSize(100,100));
        m_ImageList[i]->setViewMode(QListView::IconMode);
        m_ImageList[i]->setResizeMode(QListWidget::Adjust);
        m_ImageList[i]->setMovement(QListWidget::Static);
        m_ImageList[i]->setDragEnabled(true);
        connect(m_ImageList[i],SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(OnItemClicked(QListWidgetItem*)));
        connect(m_ImageList[i],SIGNAL(itemEntered(QListWidgetItem*)),this,SLOT(OnItemClicked(QListWidgetItem*)));
    }
}
//转移缩略图
void MaterialLibrary::ShiftImageList(int TypeOfImageList)
{
    m_TypeOfImageList=TypeOfImageList;
    for(int i=0;i<2;i++)
    {
       if(i==TypeOfImageList)
       {
          m_ImageList[i]->show();
       }
       else
      {
         m_ImageList[i]->hide();
      }
    }
}
//添加单元项
void MaterialLibrary::AppendImageList(int TypeOfImageList, QString path)
{

    //设置单元项的名字
    QStringList sections = path.split("/");
    QString name=sections.value(sections.length()-1);
    //定义QListWidgetItem对象
    QListWidgetItem *imageItem = new QListWidgetItem;
     imageItem->setText(name);

    if(TypeOfImageList==TYPE_PHOTO)
    {
        imageItem->setIcon(QIcon(path));

    }
    else
    {

    }
    //重新设置单元项图片的宽度和高度
    imageItem->setSizeHint(QSize(100,120));
    //为item储存一些必要的信息
    imageItem->setData(Qt::UserRole+1,TypeOfImageList);
    if(TypeOfImageList==TYPE_VIDEO)
    {
    imageItem->setData(Qt::UserRole,m_videoindex);
    m_videoindex++;
    }
    else
    {
        imageItem->setData(Qt::UserRole,m_photoindex);
        m_photoindex++;
    }
    //将单元项添加到QListWidget中
    m_ImageList[TypeOfImageList]->addItem(imageItem);

}
//创建起始的ui界面
void MaterialLibrary::CreateToolBar()
{
    ui->ImportButton->move(20,20);
    ui->ImportButton->resize(40,40);
    ui->ImportButton->setDefaultAction(ui->ImportIcon);
    ui->ImportButton->show();
    ui->horizontalLayoutWidget->resize(150,40);
    ui->horizontalLayoutWidget->move(80,20);
    ui->Video->resize(40,40);
    ui->Video->setDefaultAction(ui->VideoMaterial);
    ui->Photo->resize(40,40);
    ui->Photo->setDefaultAction(ui->PhotoMaterial);
    ui->HLine->resize(800,2);
    ui->HLine->move(0,62);
    ui->DeleteButton->move(250,20);
    ui->DeleteButton->resize(40,40);
    ui->DeleteButton->setDefaultAction(ui->Delete);
    ui->RenameButton->move(300,20);
    ui->RenameButton->resize(40,40);
    ui->RenameButton->setDefaultAction(ui->Rename);
}
//按下文件夹按钮后的槽函数
void MaterialLibrary::on_ImportIcon_triggered()
{

    QString path =QFileDialog::getOpenFileName(this,tr("打开文件"),"./",tr("Image Files (*.png *.jpg *.bmp);;Video files(*.mp4)"));
    QFileInfo info(path);
    QString temp=info.suffix();

    if(temp=="mp4")
    {
        InfoOfVideo info_video;
        info_video.filename=path;
        info_video.Nums=NumsOfVideo(path);
        info_video.FrameRate=FrameRateOfVideo(path);
        InfoOfVideos.push_back(info_video);
        AppendImageList(TYPE_VIDEO,path);
    }
    else
    {
        InfoOfPhoto info_Photo;
        info_Photo.filename=path;
        InfoOfPhotos.push_back(info_Photo);
        AppendImageList(TYPE_PHOTO,path);
    }
    ShiftImageList(m_TypeOfImageList);
}
//缩略图上点击图片和视频的图标可以更改缩略图
void MaterialLibrary::on_VideoMaterial_triggered()
{
    m_TypeOfImageList=TYPE_VIDEO;
    ShiftImageList(m_TypeOfImageList);
}

void MaterialLibrary::on_PhotoMaterial_triggered()
{
    m_TypeOfImageList=TYPE_PHOTO;
    ShiftImageList(m_TypeOfImageList);
}


//素材库内部的槽函数，当素材库的缩略图被点击时进入此槽函数
void MaterialLibrary::OnItemClicked(QListWidgetItem *item)
{
    //获取储存在item内的元数据信息
    int type=item->data(Qt::UserRole+1).toInt();
    int index=item->data(Qt::UserRole).toInt();
    //根据不同的类型发出不同的信号，一共有视频、图片和音频三种信号
    if(type==TYPE_VIDEO)
    {
        *info=InfoOfVideos[index];
        info->type=TYPE_VIDEO;
        emit VideoSelected(InfoOfVideos[index]);

    }
    else if(type==TYPE_PHOTO)
    {
        *info_photo=InfoOfPhotos[index];
        info->type=TYPE_PHOTO;
        emit PhotoSelected(InfoOfPhotos[index]);
    }
    m_ImageList[type]->setCurrentItem(item);
}

void MaterialLibrary::on_Delete_triggered()
{
   if(info->type!=-1)
    {
        int i;
       if(info->type==TYPE_VIDEO)
       {
            for(i=0;i<InfoOfVideos.size();i++)
            {
                if(InfoOfVideos[i].filename==info->filename)
                {
                    break;
                }
            }
            m_ImageList[info->type]->takeItem(i);
            m_videoindex--;
       }
       if(info->type==TYPE_PHOTO)
       {
            for(i=0;i<InfoOfPhotos.size();i++)
            {
                if(InfoOfPhotos[i].filename==info_photo->filename)
                {
                    break;
                }
            }
            m_ImageList[info->type]->takeItem(i);
            m_photoindex--;
       }
    }
}

void MaterialLibrary::on_Rename_triggered()
{
   if(info->type!=-1)
    {
      Rename*a=new Rename;
      connect(a,SIGNAL(Confirm(QString)),this,SLOT(OnRename(QString)));
      a->show();
    }
}
void MaterialLibrary::OnRename(QString newname)
{
  m_ImageList[info->type]->currentItem()->setText(newname);
}
void MaterialLibrary::mousePressEvent(QMouseEvent *e)
{
    if(e->button()==Qt::LeftButton)
    {
    drag=new QDrag(this);
    Qt::DropAction dropAction=drag->exec();
    }
}
//调用ffmpeg库获取视频帧率
double MaterialLibrary:: FrameRateOfVideo(QString filename)
{
    // 注册FFMpeg的库
    av_register_all();
    AVFormatContext *pFormatCtx = avformat_alloc_context(); // 存储音视频封装格式中包含的信息
    const char *filepath = filename.toStdString().c_str(); // 当前目录为构建目录
    int ret = avformat_open_input(&pFormatCtx,filepath,NULL,NULL);

    AVInputFormat *input_fmt = pFormatCtx->iformat;


    AVStream **stream = (pFormatCtx->streams);
    int den = (*stream)->avg_frame_rate.den;
    int num = (*stream)->avg_frame_rate.num;
    double rate=(double)num/(double)den;
        return rate;
}
//调用ffmpeg库获取视频帧数
int MaterialLibrary::NumsOfVideo(QString filename)
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

    const char *filepath = filename.toStdString().c_str(); // 当前目录为构建目录

    // 注册FFMpeg的库
    av_register_all();

    /*** （一）打开音视频流并获取音视频流信息 ***/
    // 初始化AVFormatContext
    pFormatCtx = avformat_alloc_context();
    // 打开音视频流
    if (avformat_open_input(&pFormatCtx, filepath, nullptr, nullptr) != 0)
    {
        printf("Couldn't open input stream.");
    }
    // 获取音视频流数据信息
    if (avformat_find_stream_info(pFormatCtx, nullptr) < 0)
    {
        printf("Couldn't find stream information.");
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
    }
    // 查找视频解码器
    pCodecCtx = pFormatCtx->streams[videoIndex]->codec; // 获取视频流编码结构
    pCodec = avcodec_find_decoder(pCodecCtx->codec_id);
    if (pCodec == nullptr)
    {
        printf("Codec not found.");
    }
    // 打开解码器
    if (avcodec_open2(pCodecCtx, pCodec, nullptr) < 0)
    {
        printf("Could not open codec.");
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
    int count=0;
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
            }
            if (got_picture)
            {
                count++;
            }
        }
        av_free_packet(packet);

    }

    /*** （四）最后要释放申请的内存空间 ***/
    sws_freeContext(img_convert_ctx); // 释放一个SwsContext
    av_frame_free(&pFrameRGB);
    av_frame_free(&pFrame);
    avcodec_close(pCodecCtx);
    avformat_close_input(&pFormatCtx);
    return count;
}
