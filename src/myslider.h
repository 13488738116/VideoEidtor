#ifndef MYSLIDER_H
#define MYSLIDER_H

#include <QSlider>
#include <QMouseEvent>
#include <QWidget>
#include <QDebug>

class MySlider : public QSlider
{
    Q_OBJECT
public:
    explicit MySlider(Qt::Orientation orientation, QWidget *parent = 0);
    ~MySlider();

signals:
    void rSliderValueManulChange(int mValue);
    void clicked();

protected:
    void mousePressEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);

};


#endif // MYSLIDER_H
