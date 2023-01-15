#ifndef VIDEOPROCESS_H
#define VIDEOPROCESS_H
#define HEIGHT_TRACK 50
#define HEIGHT_TIMELINE_PAINTER 50
#define HEIGHT_TIMELINE_WIDGET  50
#include <QFrame>
#include <QSplitter>
#include<QScrollArea>
#include <QVBoxLayout>
#include<QPushButton>
#include"timebar.h"
#include"export.h"
#include"timesegment.h"
//视频处理部分的总界面，包含时间轴以及视频槽两个部分
class TimeBar;
struct TimePoint
{
    int hour;
    int minitue;
    int second;
};
namespace Ui {
class VideoProcess;
}

class VideoProcess : public QFrame
{
    Q_OBJECT

public:
    explicit VideoProcess(QWidget *parent = 0);
    ~VideoProcess();
    void createLayout();
    void removeContent(const QString &Dir);
    TimeSegment*m_timeSegment;
    TimeBar* m_timeBar;
    QPushButton* m_export;//导出按钮
    Export *m_exportdialog;

private slots:
    void OnExport();
    void clipVideoFinished(int pos);
    void ReceiveSignal(QString format,QString resolution,QString bitrate);
private:
    Ui::VideoProcess *ui;

    qint32 track_details_count() const;




};



#endif // VIDEOPROCESS_H
