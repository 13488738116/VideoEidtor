#ifndef RENAME_H
#define RENAME_H

#include <QWidget>

namespace Ui {
class Rename;
}

class Rename : public QWidget
{
    Q_OBJECT

public:
    explicit Rename(QWidget *parent = 0);
    ~Rename();

private slots:
    void on_pushButton_clicked();
signals:
    void Confirm(QString);
public:
    Ui::Rename *ui;
};

#endif // RENAME_H
