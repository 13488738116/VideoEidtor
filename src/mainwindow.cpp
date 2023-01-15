#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"global.h"

#include<QFileDialog>
#include<QTextEdit>
#include<qDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);



    ui->VerticalLine->move(800,0);
    ui->VerticalLine->resize(2,400);
    ui->HorizontalLine->move(0,400);
    ui->HorizontalLine->resize(1600,2);
    Preview=new VideoPreview(this);
    Preview->show();
    Library=new MaterialLibrary(this);
    Library->move(800,0);
    Library->show();
    ProcessAera=new VideoProcess(this);
    ProcessAera->move(0,402);
    ProcessAera->show();
    ConnectSignals();

    QToolBar*toolBar=new QToolBar(Preview);
    toolBar->move(665,315);
    toolBar->resize(150,40);
    toolBar->addAction(ui->StartCut);
    toolBar->addAction(ui->EndCut);
    toolBar->addAction(ui->Razor);
}
//主界面链接相应的槽和信号，主要用于三个ui界面的通信
void MainWindow::ConnectSignals()
{
    connect(Library,SIGNAL(VideoSelected(InfoOfVideo)),Preview,SLOT(OnVideoSelected(InfoOfVideo)));
    connect(Library,SIGNAL(PhotoSelected(InfoOfPhoto)),Preview,SLOT(OnPhotoSelected(InfoOfPhoto)));
    connect(ProcessAera->m_timeSegment,SIGNAL(PreviewRequest(int,int)),Preview,SLOT(OnReceiveRequest(int,int)));
    connect(ui->Razor,SIGNAL(triggered()),ProcessAera->m_timeSegment,SLOT(OnReceiveRazor()));
    connect(ui->StartCut,SIGNAL(triggered()),ProcessAera->m_timeSegment,SLOT(OnReceiveCutStart()));
    connect(ui->EndCut,SIGNAL(triggered()),ProcessAera->m_timeSegment,SLOT(OnReceiveCutEnd()));
    connect(ProcessAera->m_timeSegment,SIGNAL(LibraryRequest(int,int,QString)),Library,SLOT(OnRequest(int,int,QString)));
    connect(ProcessAera->m_timeSegment,SIGNAL(PreviewRequest(int,int)),Preview,SLOT(OnReceiveRequest(int,int)));
    connect(ProcessAera->m_timeSegment,SIGNAL(PreviewChange(int)),Preview,SLOT(OnPreviewChange(int)));
    connect(Preview,SIGNAL(SubtitleImport()),ProcessAera->m_timeSegment,SLOT(OnSubtitleImport()));
}
MainWindow::~MainWindow()
{
    delete ui;
}


