#include "export.h"
#include "ui_export.h"

Export::Export(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Export)
{
    ui->setupUi(this);
}

Export::~Export()
{
    delete ui;
}

void Export::on_pushButton_clicked()
{
    emit SendSignal(ui->comboBox->currentText(),ui->comboBox_2->currentText(),ui->comboBox_3->currentText());
    this->close();
}
