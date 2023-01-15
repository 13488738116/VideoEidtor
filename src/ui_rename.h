/********************************************************************************
** Form generated from reading UI file 'rename.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RENAME_H
#define UI_RENAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Rename
{
public:
    QTextEdit *textEdit;
    QPushButton *pushButton;

    void setupUi(QWidget *Rename)
    {
        if (Rename->objectName().isEmpty())
            Rename->setObjectName(QStringLiteral("Rename"));
        Rename->resize(400, 300);
        textEdit = new QTextEdit(Rename);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(50, 40, 311, 64));
        QFont font;
        font.setFamily(QStringLiteral("Academy Engraved LET"));
        font.setPointSize(16);
        textEdit->setFont(font);
        pushButton = new QPushButton(Rename);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(139, 170, 121, 51));
        pushButton->setFont(font);

        retranslateUi(Rename);

        QMetaObject::connectSlotsByName(Rename);
    } // setupUi

    void retranslateUi(QWidget *Rename)
    {
        Rename->setWindowTitle(QApplication::translate("Rename", "Form", 0));
        pushButton->setText(QApplication::translate("Rename", "\347\241\256\345\256\232", 0));
    } // retranslateUi

};

namespace Ui {
    class Rename: public Ui_Rename {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RENAME_H
