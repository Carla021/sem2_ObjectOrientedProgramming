/********************************************************************************
** Form generated from reading UI file 'eventsgui.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EVENTSGUI_H
#define UI_EVENTSGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_eventsGUI
{
public:

    void setupUi(QWidget *eventsGUI)
    {
        if (eventsGUI->objectName().isEmpty())
            eventsGUI->setObjectName("eventsGUI");
        eventsGUI->resize(400, 300);

        retranslateUi(eventsGUI);

        QMetaObject::connectSlotsByName(eventsGUI);
    } // setupUi

    void retranslateUi(QWidget *eventsGUI)
    {
        eventsGUI->setWindowTitle(QCoreApplication::translate("eventsGUI", "eventsGUI", nullptr));
    } // retranslateUi

};

namespace Ui {
    class eventsGUI: public Ui_eventsGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EVENTSGUI_H
