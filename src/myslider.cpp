#include "myslider.h"

MySlider::MySlider(Qt::Orientation orientation,QWidget *parent):QSlider(orientation,parent)
{

}

MySlider::~MySlider()
{

}

void MySlider::mousePressEvent(QMouseEvent *ev)
{
    QSlider::mousePressEvent(ev);//调用父类的鼠标点击处理事件，这样可以不影响拖动的情况
    double pos = ev->pos().x() / (double)width();//获取按下时相对滑动条所在的比例
    double value = pos * (maximum() - minimum()) + minimum();//计算按下时的位置
    if(value > maximum())
    {
        value = maximum();
    }
    if(value < minimum())
    {
        value = minimum();
    }
    int mValue = value + 0.5;//四舍五入
    setValue(mValue);
    emit rSliderValueManulChange(mValue);//发送输出信号
    emit clicked();
}

void MySlider::mouseReleaseEvent(QMouseEvent *ev)
{
    QSlider::mouseReleaseEvent(ev);
    double pos = ev->pos().x() / (double)width();
    double value = pos * (maximum() - minimum()) + minimum();
    if(value > maximum())
    {
        value = maximum();
    }
    if(value < minimum())
    {
        value = minimum();
    }
    int mValue = value + 0.5;
    setValue(mValue);
    emit rSliderValueManulChange(mValue);
}
