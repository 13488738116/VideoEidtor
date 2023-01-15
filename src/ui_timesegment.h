/********************************************************************************
** Form generated from reading UI file 'timesegment.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIMESEGMENT_H
#define UI_TIMESEGMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TimeSegment
{
public:
    QFrame *line;
    QFrame *line_2;
    QFrame *line_3;
    QFrame *line_4;
    QFrame *line_5;
    QFrame *line_6;
    QFrame *line_7;

    void setupUi(QWidget *TimeSegment)
    {
        if (TimeSegment->objectName().isEmpty())
            TimeSegment->setObjectName(QStringLiteral("TimeSegment"));
        TimeSegment->resize(1360, 600);
        TimeSegment->setStyleSheet(QStringLiteral(""));
        line = new QFrame(TimeSegment);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(10, 60, 118, 3));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(TimeSegment);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(10, 130, 118, 3));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(TimeSegment);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(10, 220, 118, 3));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line_4 = new QFrame(TimeSegment);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setGeometry(QRect(80, 70, 118, 3));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        line_5 = new QFrame(TimeSegment);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setGeometry(QRect(110, 140, 118, 3));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);
        line_6 = new QFrame(TimeSegment);
        line_6->setObjectName(QStringLiteral("line_6"));
        line_6->setGeometry(QRect(280, 80, 3, 61));
        line_6->setFrameShape(QFrame::VLine);
        line_6->setFrameShadow(QFrame::Sunken);
        line_7 = new QFrame(TimeSegment);
        line_7->setObjectName(QStringLiteral("line_7"));
        line_7->setGeometry(QRect(110, 300, 118, 3));
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);

        retranslateUi(TimeSegment);

        QMetaObject::connectSlotsByName(TimeSegment);
    } // setupUi

    void retranslateUi(QWidget *TimeSegment)
    {
        TimeSegment->setWindowTitle(QApplication::translate("TimeSegment", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class TimeSegment: public Ui_TimeSegment {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIMESEGMENT_H
