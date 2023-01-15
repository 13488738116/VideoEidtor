/********************************************************************************
** Form generated from reading UI file 'materiallibrary.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MATERIALLIBRARY_H
#define UI_MATERIALLIBRARY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MaterialLibrary
{
public:
    QAction *ImportIcon;
    QAction *VideoMaterial;
    QAction *PhotoMaterial;
    QAction *Delete;
    QAction *Rename;
    QToolButton *ImportButton;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QToolButton *Video;
    QToolButton *Photo;
    QFrame *HLine;
    QToolButton *DeleteButton;
    QToolButton *RenameButton;

    void setupUi(QWidget *MaterialLibrary)
    {
        if (MaterialLibrary->objectName().isEmpty())
            MaterialLibrary->setObjectName(QStringLiteral("MaterialLibrary"));
        MaterialLibrary->resize(800, 500);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MaterialLibrary->sizePolicy().hasHeightForWidth());
        MaterialLibrary->setSizePolicy(sizePolicy);
        ImportIcon = new QAction(MaterialLibrary);
        ImportIcon->setObjectName(QStringLiteral("ImportIcon"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/prefix1/sourse/File.png"), QSize(), QIcon::Normal, QIcon::Off);
        ImportIcon->setIcon(icon);
        VideoMaterial = new QAction(MaterialLibrary);
        VideoMaterial->setObjectName(QStringLiteral("VideoMaterial"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/new/prefix1/sourse/Video.png"), QSize(), QIcon::Normal, QIcon::Off);
        VideoMaterial->setIcon(icon1);
        PhotoMaterial = new QAction(MaterialLibrary);
        PhotoMaterial->setObjectName(QStringLiteral("PhotoMaterial"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/new/prefix1/sourse/Photo.png"), QSize(), QIcon::Normal, QIcon::Off);
        PhotoMaterial->setIcon(icon2);
        Delete = new QAction(MaterialLibrary);
        Delete->setObjectName(QStringLiteral("Delete"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/new/prefix1/sourse/Delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        Delete->setIcon(icon3);
        Rename = new QAction(MaterialLibrary);
        Rename->setObjectName(QStringLiteral("Rename"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/new/prefix1/sourse/Rename.png"), QSize(), QIcon::Normal, QIcon::Off);
        Rename->setIcon(icon4);
        ImportButton = new QToolButton(MaterialLibrary);
        ImportButton->setObjectName(QStringLiteral("ImportButton"));
        ImportButton->setGeometry(QRect(21, 40, 41, 31));
        horizontalLayoutWidget = new QWidget(MaterialLibrary);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(120, 40, 160, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        Video = new QToolButton(horizontalLayoutWidget);
        Video->setObjectName(QStringLiteral("Video"));
        Video->setCheckable(true);
        Video->setAutoExclusive(true);

        horizontalLayout->addWidget(Video);

        Photo = new QToolButton(horizontalLayoutWidget);
        Photo->setObjectName(QStringLiteral("Photo"));
        Photo->setCheckable(true);
        Photo->setAutoExclusive(true);

        horizontalLayout->addWidget(Photo);

        HLine = new QFrame(MaterialLibrary);
        HLine->setObjectName(QStringLiteral("HLine"));
        HLine->setGeometry(QRect(80, 120, 118, 3));
        HLine->setFrameShape(QFrame::HLine);
        HLine->setFrameShadow(QFrame::Sunken);
        DeleteButton = new QToolButton(MaterialLibrary);
        DeleteButton->setObjectName(QStringLiteral("DeleteButton"));
        DeleteButton->setGeometry(QRect(50, 150, 32, 16));
        RenameButton = new QToolButton(MaterialLibrary);
        RenameButton->setObjectName(QStringLiteral("RenameButton"));
        RenameButton->setGeometry(QRect(130, 210, 32, 16));

        retranslateUi(MaterialLibrary);

        QMetaObject::connectSlotsByName(MaterialLibrary);
    } // setupUi

    void retranslateUi(QWidget *MaterialLibrary)
    {
        MaterialLibrary->setWindowTitle(QApplication::translate("MaterialLibrary", "Form", 0));
        ImportIcon->setText(QApplication::translate("MaterialLibrary", "\345\257\274\345\205\245\346\226\207\344\273\266", 0));
        VideoMaterial->setText(QApplication::translate("MaterialLibrary", "\350\247\206\351\242\221\347\264\240\346\235\220\345\272\223", 0));
        PhotoMaterial->setText(QApplication::translate("MaterialLibrary", "\345\233\276\347\211\207\347\264\240\346\235\220\345\272\223", 0));
        Delete->setText(QApplication::translate("MaterialLibrary", "\345\210\240\351\231\244\347\264\240\346\235\220", 0));
        Rename->setText(QApplication::translate("MaterialLibrary", "\351\207\215\345\221\275\345\220\215", 0));
        ImportButton->setText(QApplication::translate("MaterialLibrary", "...", 0));
        Video->setText(QApplication::translate("MaterialLibrary", "...", 0));
        Photo->setText(QApplication::translate("MaterialLibrary", "...", 0));
        DeleteButton->setText(QApplication::translate("MaterialLibrary", "...", 0));
        RenameButton->setText(QApplication::translate("MaterialLibrary", "...", 0));
    } // retranslateUi

};

namespace Ui {
    class MaterialLibrary: public Ui_MaterialLibrary {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MATERIALLIBRARY_H
