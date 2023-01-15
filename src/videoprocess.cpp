#include "videoprocess.h"
#include "ui_videoprocess.h"
#include<QMessageBox>
#include<QFileInfo>
#include<QDir>
VideoProcess::VideoProcess(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::VideoProcess)
{
    ui->setupUi(this);
    createLayout();
    //buildUI();

}

VideoProcess::~VideoProcess()
{
    delete ui;
}
void VideoProcess::createLayout()
{



    QPushButton* Slot1=new QPushButton(this);
    Slot1->resize(150,100);
    Slot1->move(10,90);
    Slot1->setEnabled(false);
    Slot1->setText("播放轴");
    QPushButton* Slot2=new QPushButton(this);
    Slot2->resize(150,100);
    Slot2->move(10,190);
    Slot2->setEnabled(false);
    Slot2->setText("视频轴1");
    QPushButton* Slot3=new QPushButton(this);
    Slot3->resize(150,100);
    Slot3->move(10,290);
    Slot3->setEnabled(false);
    Slot3->setText("视频轴2");
    QPushButton* Slot4=new QPushButton(this);
    Slot4->resize(150,100);
    Slot4->move(10,390);
    Slot4->setEnabled(false);
    Slot4->setText("字幕轴");

    QPushButton* Slot5=new QPushButton(this);
    Slot5->resize(150,100);
    Slot5->move(10,490);
    Slot5->setEnabled(false);
    Slot5->setText("图片轴");

   m_export=new QPushButton(this);
   m_export->resize(80,50);
   m_export->move(30,30);
   m_export->setText("导出");
   connect(m_export,SIGNAL(clicked()),this,SLOT(OnExport()));

    m_timeBar=new TimeBar(this);
    m_timeBar->resize(1500,80);
    m_timeBar->move(150,10);

    m_timeSegment=new TimeSegment(this);
    m_timeSegment->move(160,90);
    m_timeSegment->resize(1360,550);
    m_timeSegment->setAcceptDrops(true);
    connect(m_timeBar,SIGNAL(SignalSendXline(double)),m_timeSegment,SLOT(OnReceiveXline(double)));
    connect(m_timeSegment,SIGNAL(SignalSendXline(double)),m_timeBar,SLOT(OnReceiveXline(double)));

}
//按下导出按钮后先弹出对话框设置码率、分辨率以及格式等信息
void VideoProcess::OnExport()
{

    m_exportdialog=new Export;
    m_exportdialog->show();
    connect(m_exportdialog,SIGNAL(SendSignal(QString,QString,QString)),this,SLOT(ReceiveSignal(QString,QString,QString)));


}
//由于导出视频用到了一个暂时生成的图片序列，所以最后要把这些都删除掉
void VideoProcess::removeContent(const QString &Dir)
{
    QDir dir(Dir);
    QFileInfoList fileList;
    QFileInfo curFile;
    if(!dir.exists())  {return;}//文件不存，则返回false
    fileList=dir.entryInfoList(QDir::Dirs|QDir::Files
                               |QDir::Readable|QDir::Writable
                               |QDir::Hidden|QDir::NoDotAndDotDot
                               ,QDir::Name);
    while(fileList.size()>0)
    {
        int infoNum=fileList.size();
        for(int i=infoNum-1;i>=0;i--)
        {
            curFile=fileList[i];
            if(curFile.isFile())
            {
                QFile fileTemp(curFile.filePath());
                fileTemp.remove();
                fileList.removeAt(i);
            }

        }
    }

}
//导出视频提示框
void VideoProcess::clipVideoFinished(int pos)
{
    QFileInfo finfo("./VideoProcess.exe");
     removeContent(finfo.absolutePath()+"/"+"temp");
     QMessageBox MyBox(QMessageBox::Information,"Information","导出完成",QMessageBox::Ok);
     MyBox.exec();
}
//调用ffmpeg命令行将图片序列导出为对应格式的文件
void VideoProcess::ReceiveSignal(QString format,QString resolution,QString bitrate)
{
    //创建video.txt
    QFileInfo finfo("./VideoProcess.exe");
    QString filename=finfo.absolutePath()+"/"+"temp"+"/"+"%d.jpeg";
    //设置视频导出路径
    QString output=finfo.absolutePath()+"/"+"output"+"/output"+format;
    QString program=finfo.absolutePath()+"\\Dev\\bin\\ffmpeg.exe";
    QStringList arguments;
    arguments<<"-r"<<"30"<<"-i"<<filename<<"-vcodec"<<"h264"<<"-s"<<resolution<<"-b:v"<<bitrate<<output;
    qDebug()<<filename<<resolution<<bitrate<<output;
    QProcess *process=new QProcess(this);
    connect(process,SIGNAL(finished(int)),this,SLOT(clipVideoFinished(int)));
    process->start(program,arguments);
}

