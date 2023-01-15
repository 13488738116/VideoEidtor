#ifndef SETTINGPHOTO_H
#define SETTINGPHOTO_H

#include"global.h"
#include <QWidget>

namespace Ui {
class SettingPhoto;
}

class SettingPhoto : public QWidget
{
    Q_OBJECT

public:
    explicit SettingPhoto(QWidget *parent = 0);
    ~SettingPhoto();

private slots:
    void on_pushButton_clicked();
signals:
    void PhotoSetting(double,int,int,int,int);
private:
    Ui::SettingPhoto *ui;
};

#endif // SETTINGPHOTO_H
