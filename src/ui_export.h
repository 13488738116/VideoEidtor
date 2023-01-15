/********************************************************************************
** Form generated from reading UI file 'export.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPORT_H
#define UI_EXPORT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Export
{
public:
    QComboBox *comboBox;
    QLabel *label;
    QLabel *label_2;
    QComboBox *comboBox_2;
    QLabel *label_3;
    QComboBox *comboBox_3;
    QPushButton *pushButton;

    void setupUi(QWidget *Export)
    {
        if (Export->objectName().isEmpty())
            Export->setObjectName(QStringLiteral("Export"));
        Export->resize(400, 300);
        comboBox = new QComboBox(Export);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(110, 30, 151, 22));
        label = new QLabel(Export);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 30, 101, 21));
        QFont font;
        font.setFamily(QStringLiteral("Academy Engraved LET"));
        font.setPointSize(12);
        label->setFont(font);
        label_2 = new QLabel(Export);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 100, 101, 21));
        label_2->setFont(font);
        comboBox_2 = new QComboBox(Export);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setGeometry(QRect(110, 100, 151, 22));
        label_3 = new QLabel(Export);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 170, 101, 21));
        label_3->setFont(font);
        comboBox_3 = new QComboBox(Export);
        comboBox_3->setObjectName(QStringLiteral("comboBox_3"));
        comboBox_3->setGeometry(QRect(110, 170, 151, 22));
        pushButton = new QPushButton(Export);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(110, 230, 151, 41));
        QFont font1;
        font1.setFamily(QStringLiteral("Academy Engraved LET"));
        font1.setPointSize(16);
        pushButton->setFont(font1);

        retranslateUi(Export);

        QMetaObject::connectSlotsByName(Export);
    } // setupUi

    void retranslateUi(QWidget *Export)
    {
        Export->setWindowTitle(QApplication::translate("Export", "Form", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("Export", ".mp4", 0)
         << QApplication::translate("Export", ".avi", 0)
        );
        label->setText(QApplication::translate("Export", "\350\247\206\351\242\221\346\240\274\345\274\217", 0));
        label_2->setText(QApplication::translate("Export", "\350\247\206\351\242\221\345\210\206\350\276\250\347\216\207", 0));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("Export", "640*480", 0)
         << QApplication::translate("Export", "720*576", 0)
         << QApplication::translate("Export", "1080*720", 0)
        );
        label_3->setText(QApplication::translate("Export", "\350\247\206\351\242\221\347\240\201\347\216\207", 0));
        comboBox_3->clear();
        comboBox_3->insertItems(0, QStringList()
         << QApplication::translate("Export", "1500k", 0)
         << QApplication::translate("Export", "3500k", 0)
         << QApplication::translate("Export", "5000k", 0)
        );
        pushButton->setText(QApplication::translate("Export", "\347\241\256\345\256\232", 0));
    } // retranslateUi

};

namespace Ui {
    class Export: public Ui_Export {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPORT_H
