/********************************************************************************
** Form generated from reading UI file 'settingphoto.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGPHOTO_H
#define UI_SETTINGPHOTO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingPhoto
{
public:
    QLabel *label;
    QTextEdit *textEdit;
    QLabel *label_2;
    QTextEdit *textEdit_2;
    QTextEdit *textEdit_3;
    QLabel *label_3;
    QTextEdit *textEdit_4;
    QLabel *label_4;
    QComboBox *comboBox;
    QPushButton *pushButton;

    void setupUi(QWidget *SettingPhoto)
    {
        if (SettingPhoto->objectName().isEmpty())
            SettingPhoto->setObjectName(QStringLiteral("SettingPhoto"));
        SettingPhoto->resize(400, 243);
        label = new QLabel(SettingPhoto);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 20, 131, 21));
        textEdit = new QTextEdit(SettingPhoto);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(30, 40, 104, 31));
        label_2 = new QLabel(SettingPhoto);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 80, 141, 21));
        textEdit_2 = new QTextEdit(SettingPhoto);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));
        textEdit_2->setGeometry(QRect(30, 110, 61, 31));
        textEdit_3 = new QTextEdit(SettingPhoto);
        textEdit_3->setObjectName(QStringLiteral("textEdit_3"));
        textEdit_3->setGeometry(QRect(103, 110, 61, 31));
        label_3 = new QLabel(SettingPhoto);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 160, 181, 21));
        textEdit_4 = new QTextEdit(SettingPhoto);
        textEdit_4->setObjectName(QStringLiteral("textEdit_4"));
        textEdit_4->setGeometry(QRect(30, 180, 104, 31));
        label_4 = new QLabel(SettingPhoto);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(210, 20, 91, 21));
        comboBox = new QComboBox(SettingPhoto);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(210, 40, 151, 22));
        pushButton = new QPushButton(SettingPhoto);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(250, 170, 80, 41));
        QFont font;
        font.setFamily(QStringLiteral("Academy Engraved LET"));
        font.setPointSize(14);
        pushButton->setFont(font);

        retranslateUi(SettingPhoto);

        QMetaObject::connectSlotsByName(SettingPhoto);
    } // setupUi

    void retranslateUi(QWidget *SettingPhoto)
    {
        SettingPhoto->setWindowTitle(QApplication::translate("SettingPhoto", "Form", 0));
        label->setText(QApplication::translate("SettingPhoto", "\345\233\276\347\211\207\347\274\251\346\224\276\345\233\240\345\255\220(0-1)\357\274\232", 0));
        label_2->setText(QApplication::translate("SettingPhoto", "\346\250\252\347\272\265\345\235\220\346\240\207\357\274\232", 0));
        label_3->setText(QApplication::translate("SettingPhoto", "\346\222\255\346\224\276\346\227\266\351\225\277(\345\215\225\344\275\215ms)\357\274\232", 0));
        label_4->setText(QApplication::translate("SettingPhoto", "\347\211\271\346\225\210\351\200\211\346\213\251\357\274\232", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("SettingPhoto", "\346\227\240\347\211\271\346\225\210", 0)
         << QApplication::translate("SettingPhoto", "\347\274\251\346\224\276\347\211\271\346\225\210", 0)
         << QApplication::translate("SettingPhoto", "\345\271\263\347\247\273\347\211\271\346\225\210", 0)
         << QApplication::translate("SettingPhoto", "\346\267\241\345\205\245", 0)
         << QApplication::translate("SettingPhoto", "\346\267\241\345\207\272", 0)
        );
        pushButton->setText(QApplication::translate("SettingPhoto", "\347\241\256\345\256\232", 0));
    } // retranslateUi

};

namespace Ui {
    class SettingPhoto: public Ui_SettingPhoto {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGPHOTO_H
