/********************************************************************************
** Form generated from reading UI file 'usergui.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERGUI_H
#define UI_USERGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_userGUI
{
public:
    QGridLayout *gridLayout_2;
    QLabel *label_4;
    QListWidget *givenMonthListWidget;
    QLabel *label_5;
    QListWidget *listListWidget;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLineEdit *givenMonthLineEdit;
    QLabel *label;
    QGridLayout *gridLayout;
    QLabel *label_6;
    QLineEdit *TitleLineEdit;
    QLabel *label_7;
    QLineEdit *DescriptionLineEdit_2;
    QLabel *label_8;
    QLineEdit *DTLineEdit_3;
    QLabel *label_9;
    QLineEdit *NbPLineEdit_4;
    QLabel *label_10;
    QLineEdit *linkLineEdit_5;
    QFormLayout *formLayout_4;
    QLabel *label_3;
    QLineEdit *titleLineEdit;
    QFormLayout *formLayout_2;
    QPushButton *monthPushButton;
    QPushButton *AddPushButton;
    QPushButton *fileTypePushButton;
    QPushButton *DeletePushButton;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *fileTypeLineEdit;

    void setupUi(QWidget *userGUI)
    {
        if (userGUI->objectName().isEmpty())
            userGUI->setObjectName("userGUI");
        userGUI->resize(836, 564);
        gridLayout_2 = new QGridLayout(userGUI);
        gridLayout_2->setObjectName("gridLayout_2");
        label_4 = new QLabel(userGUI);
        label_4->setObjectName("label_4");

        gridLayout_2->addWidget(label_4, 0, 0, 1, 1);

        givenMonthListWidget = new QListWidget(userGUI);
        givenMonthListWidget->setObjectName("givenMonthListWidget");

        gridLayout_2->addWidget(givenMonthListWidget, 1, 0, 1, 2);

        label_5 = new QLabel(userGUI);
        label_5->setObjectName("label_5");

        gridLayout_2->addWidget(label_5, 2, 0, 1, 1);

        listListWidget = new QListWidget(userGUI);
        listListWidget->setObjectName("listListWidget");

        gridLayout_2->addWidget(listListWidget, 3, 0, 1, 2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        givenMonthLineEdit = new QLineEdit(userGUI);
        givenMonthLineEdit->setObjectName("givenMonthLineEdit");

        formLayout->setWidget(0, QFormLayout::FieldRole, givenMonthLineEdit);

        label = new QLabel(userGUI);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::LabelRole, label);


        verticalLayout->addLayout(formLayout);


        gridLayout_2->addLayout(verticalLayout, 4, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        label_6 = new QLabel(userGUI);
        label_6->setObjectName("label_6");

        gridLayout->addWidget(label_6, 0, 0, 1, 1);

        TitleLineEdit = new QLineEdit(userGUI);
        TitleLineEdit->setObjectName("TitleLineEdit");

        gridLayout->addWidget(TitleLineEdit, 0, 1, 1, 3);

        label_7 = new QLabel(userGUI);
        label_7->setObjectName("label_7");

        gridLayout->addWidget(label_7, 1, 0, 1, 2);

        DescriptionLineEdit_2 = new QLineEdit(userGUI);
        DescriptionLineEdit_2->setObjectName("DescriptionLineEdit_2");

        gridLayout->addWidget(DescriptionLineEdit_2, 1, 2, 1, 2);

        label_8 = new QLabel(userGUI);
        label_8->setObjectName("label_8");

        gridLayout->addWidget(label_8, 2, 0, 1, 2);

        DTLineEdit_3 = new QLineEdit(userGUI);
        DTLineEdit_3->setObjectName("DTLineEdit_3");

        gridLayout->addWidget(DTLineEdit_3, 2, 2, 1, 2);

        label_9 = new QLabel(userGUI);
        label_9->setObjectName("label_9");

        gridLayout->addWidget(label_9, 3, 0, 1, 3);

        NbPLineEdit_4 = new QLineEdit(userGUI);
        NbPLineEdit_4->setObjectName("NbPLineEdit_4");

        gridLayout->addWidget(NbPLineEdit_4, 3, 3, 1, 1);

        label_10 = new QLabel(userGUI);
        label_10->setObjectName("label_10");

        gridLayout->addWidget(label_10, 4, 0, 1, 1);

        linkLineEdit_5 = new QLineEdit(userGUI);
        linkLineEdit_5->setObjectName("linkLineEdit_5");

        gridLayout->addWidget(linkLineEdit_5, 4, 1, 1, 3);


        gridLayout_2->addLayout(gridLayout, 4, 1, 3, 1);

        formLayout_4 = new QFormLayout();
        formLayout_4->setObjectName("formLayout_4");
        label_3 = new QLabel(userGUI);
        label_3->setObjectName("label_3");

        formLayout_4->setWidget(0, QFormLayout::LabelRole, label_3);

        titleLineEdit = new QLineEdit(userGUI);
        titleLineEdit->setObjectName("titleLineEdit");

        formLayout_4->setWidget(0, QFormLayout::FieldRole, titleLineEdit);


        gridLayout_2->addLayout(formLayout_4, 5, 0, 1, 1);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName("formLayout_2");
        monthPushButton = new QPushButton(userGUI);
        monthPushButton->setObjectName("monthPushButton");

        formLayout_2->setWidget(0, QFormLayout::LabelRole, monthPushButton);

        AddPushButton = new QPushButton(userGUI);
        AddPushButton->setObjectName("AddPushButton");

        formLayout_2->setWidget(0, QFormLayout::FieldRole, AddPushButton);

        fileTypePushButton = new QPushButton(userGUI);
        fileTypePushButton->setObjectName("fileTypePushButton");

        formLayout_2->setWidget(1, QFormLayout::LabelRole, fileTypePushButton);

        DeletePushButton = new QPushButton(userGUI);
        DeletePushButton->setObjectName("DeletePushButton");

        formLayout_2->setWidget(1, QFormLayout::FieldRole, DeletePushButton);


        gridLayout_2->addLayout(formLayout_2, 6, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_2 = new QLabel(userGUI);
        label_2->setObjectName("label_2");

        horizontalLayout->addWidget(label_2);

        fileTypeLineEdit = new QLineEdit(userGUI);
        fileTypeLineEdit->setObjectName("fileTypeLineEdit");

        horizontalLayout->addWidget(fileTypeLineEdit);


        gridLayout_2->addLayout(horizontalLayout, 7, 0, 1, 2);


        retranslateUi(userGUI);

        QMetaObject::connectSlotsByName(userGUI);
    } // setupUi

    void retranslateUi(QWidget *userGUI)
    {
        userGUI->setWindowTitle(QCoreApplication::translate("userGUI", "userGUI", nullptr));
        label_4->setText(QCoreApplication::translate("userGUI", "The events for the given month:", nullptr));
        label_5->setText(QCoreApplication::translate("userGUI", "The events you want to attend:", nullptr));
        label->setText(QCoreApplication::translate("userGUI", "Enter the month you want to see the events:", nullptr));
        label_6->setText(QCoreApplication::translate("userGUI", "Title:", nullptr));
        label_7->setText(QCoreApplication::translate("userGUI", "Description:", nullptr));
        label_8->setText(QCoreApplication::translate("userGUI", "Date and time:", nullptr));
        label_9->setText(QCoreApplication::translate("userGUI", "number of people:", nullptr));
        label_10->setText(QCoreApplication::translate("userGUI", "link:", nullptr));
        label_3->setText(QCoreApplication::translate("userGUI", "Title of the event you want to delete: ", nullptr));
        monthPushButton->setText(QCoreApplication::translate("userGUI", "See events for the given month", nullptr));
        AddPushButton->setText(QCoreApplication::translate("userGUI", "Add event", nullptr));
        fileTypePushButton->setText(QCoreApplication::translate("userGUI", "See the events in the given file type", nullptr));
        DeletePushButton->setText(QCoreApplication::translate("userGUI", "Delete event", nullptr));
        label_2->setText(QCoreApplication::translate("userGUI", "Enter the type of the file in which you want to save the list of events(csv or html):", nullptr));
    } // retranslateUi

};

namespace Ui {
    class userGUI: public Ui_userGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERGUI_H
