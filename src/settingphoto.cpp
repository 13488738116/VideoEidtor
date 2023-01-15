#include "settingphoto.h"
#include "ui_settingphoto.h"

SettingPhoto::SettingPhoto(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SettingPhoto)
{
    ui->setupUi(this);
}

SettingPhoto::~SettingPhoto()
{
    delete ui;
}

void SettingPhoto::on_pushButton_clicked()
{
   double fac= ui->textEdit->toPlainText().toDouble();
   int x=ui->textEdit_2->toPlainText().toInt();
   int y=ui->textEdit_3->toPlainText().toInt();
   int duration=ui->textEdit_4->toPlainText().toInt();
   int effect=ui->comboBox->currentIndex();
    emit PhotoSetting(fac,x,y,duration,effect);
   this->close();
}
