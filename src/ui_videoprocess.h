/********************************************************************************
** Form generated from reading UI file 'videoprocess.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEOPROCESS_H
#define UI_VIDEOPROCESS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_VideoProcess
{
public:

    void setupUi(QFrame *VideoProcess)
    {
        if (VideoProcess->objectName().isEmpty())
            VideoProcess->setObjectName(QStringLiteral("VideoProcess"));
        VideoProcess->resize(1600, 600);
        VideoProcess->setFrameShape(QFrame::StyledPanel);
        VideoProcess->setFrameShadow(QFrame::Raised);

        retranslateUi(VideoProcess);

        QMetaObject::connectSlotsByName(VideoProcess);
    } // setupUi

    void retranslateUi(QFrame *VideoProcess)
    {
        VideoProcess->setWindowTitle(QApplication::translate("VideoProcess", "Frame", 0));
    } // retranslateUi

};

namespace Ui {
    class VideoProcess: public Ui_VideoProcess {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEOPROCESS_H
