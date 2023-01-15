/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *Razor;
    QAction *StartCut;
    QAction *EndCut;
    QWidget *centralWidget;
    QFrame *VerticalLine;
    QFrame *HorizontalLine;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1600, 1000);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        Razor = new QAction(MainWindow);
        Razor->setObjectName(QStringLiteral("Razor"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/prefix1/sourse/razor.png"), QSize(), QIcon::Normal, QIcon::Off);
        Razor->setIcon(icon);
        StartCut = new QAction(MainWindow);
        StartCut->setObjectName(QStringLiteral("StartCut"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/new/prefix1/sourse/StartCut.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        StartCut->setIcon(icon1);
        EndCut = new QAction(MainWindow);
        EndCut->setObjectName(QStringLiteral("EndCut"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/new/prefix1/sourse/EndCut.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        EndCut->setIcon(icon2);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        VerticalLine = new QFrame(centralWidget);
        VerticalLine->setObjectName(QStringLiteral("VerticalLine"));
        VerticalLine->setGeometry(QRect(10, 0, 3, 61));
        VerticalLine->setFrameShape(QFrame::VLine);
        VerticalLine->setFrameShadow(QFrame::Sunken);
        HorizontalLine = new QFrame(centralWidget);
        HorizontalLine->setObjectName(QStringLiteral("HorizontalLine"));
        HorizontalLine->setGeometry(QRect(20, 0, 118, 3));
        HorizontalLine->setFrameShape(QFrame::HLine);
        HorizontalLine->setFrameShadow(QFrame::Sunken);
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        Razor->setText(QApplication::translate("MainWindow", "\350\247\206\351\242\221\345\210\207\345\210\206", 0));
        StartCut->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213\346\210\252\345\217\226", 0));
        EndCut->setText(QApplication::translate("MainWindow", "\347\273\223\346\235\237\346\210\252\345\217\226", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
