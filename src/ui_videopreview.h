/********************************************************************************
** Form generated from reading UI file 'videopreview.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEOPREVIEW_H
#define UI_VIDEOPREVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VideoPreview
{
public:
    QAction *PreviewIcon;
    QAction *PreviousFrame;
    QAction *NextFrame;
    QAction *Subtitle;

    void setupUi(QWidget *VideoPreview)
    {
        if (VideoPreview->objectName().isEmpty())
            VideoPreview->setObjectName(QStringLiteral("VideoPreview"));
        VideoPreview->resize(800, 500);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(VideoPreview->sizePolicy().hasHeightForWidth());
        VideoPreview->setSizePolicy(sizePolicy);
        VideoPreview->setStyleSheet(QStringLiteral(""));
        PreviewIcon = new QAction(VideoPreview);
        PreviewIcon->setObjectName(QStringLiteral("PreviewIcon"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/prefix1/sourse/Preview.png"), QSize(), QIcon::Normal, QIcon::Off);
        PreviewIcon->setIcon(icon);
        PreviousFrame = new QAction(VideoPreview);
        PreviousFrame->setObjectName(QStringLiteral("PreviousFrame"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/new/prefix1/sourse/PreviousFrame.png"), QSize(), QIcon::Normal, QIcon::Off);
        PreviousFrame->setIcon(icon1);
        NextFrame = new QAction(VideoPreview);
        NextFrame->setObjectName(QStringLiteral("NextFrame"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/new/prefix1/sourse/NextFrame.png"), QSize(), QIcon::Normal, QIcon::Off);
        NextFrame->setIcon(icon2);
        Subtitle = new QAction(VideoPreview);
        Subtitle->setObjectName(QStringLiteral("Subtitle"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/new/prefix1/sourse/Subtitle.png"), QSize(), QIcon::Normal, QIcon::Off);
        Subtitle->setIcon(icon3);

        retranslateUi(VideoPreview);

        QMetaObject::connectSlotsByName(VideoPreview);
    } // setupUi

    void retranslateUi(QWidget *VideoPreview)
    {
        VideoPreview->setWindowTitle(QApplication::translate("VideoPreview", "Form", 0));
        PreviewIcon->setText(QApplication::translate("VideoPreview", "\351\242\204\350\247\210", 0));
        PreviousFrame->setText(QApplication::translate("VideoPreview", "\344\270\212\344\270\200\345\270\247", 0));
        NextFrame->setText(QApplication::translate("VideoPreview", "\344\270\213\344\270\200\345\270\247", 0));
        Subtitle->setText(QApplication::translate("VideoPreview", "\345\255\227\345\271\225\346\267\273\345\212\240", 0));
    } // retranslateUi

};

namespace Ui {
    class VideoPreview: public Ui_VideoPreview {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEOPREVIEW_H
