#ifndef EXPORT_H
#define EXPORT_H
#include"global.h"
#include <QWidget>

namespace Ui {
class Export;
}

class Export : public QWidget
{
    Q_OBJECT

public:
    explicit Export(QWidget *parent = 0);
    ~Export();
signals:
    void SendSignal(QString,QString,QString);
private slots:
    void on_pushButton_clicked();

private:
    Ui::Export *ui;
};

#endif // EXPORT_H
