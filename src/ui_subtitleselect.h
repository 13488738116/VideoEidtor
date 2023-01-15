/********************************************************************************
** Form generated from reading UI file 'subtitleselect.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUBTITLESELECT_H
#define UI_SUBTITLESELECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SubtitleSelect
{
public:

    void setupUi(QWidget *SubtitleSelect)
    {
        if (SubtitleSelect->objectName().isEmpty())
            SubtitleSelect->setObjectName(QStringLiteral("SubtitleSelect"));
        SubtitleSelect->resize(400, 300);

        retranslateUi(SubtitleSelect);

        QMetaObject::connectSlotsByName(SubtitleSelect);
    } // setupUi

    void retranslateUi(QWidget *SubtitleSelect)
    {
        SubtitleSelect->setWindowTitle(QApplication::translate("SubtitleSelect", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class SubtitleSelect: public Ui_SubtitleSelect {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUBTITLESELECT_H
