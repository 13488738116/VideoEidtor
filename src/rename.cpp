#include "rename.h"
#include "ui_rename.h"

Rename::Rename(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Rename)
{
    ui->setupUi(this);
}

Rename::~Rename()
{
    delete ui;
}

void Rename::on_pushButton_clicked()
{
   emit Confirm(ui->textEdit->toPlainText());
    this->close();
}
