/********************************************************************************
** Form generated from reading UI file 'chatwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATWINDOW_H
#define UI_CHATWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_chatWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *chatWindow)
    {
        if (chatWindow->objectName().isEmpty())
            chatWindow->setObjectName("chatWindow");
        chatWindow->resize(750, 500);
        centralwidget = new QWidget(chatWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(240, 150, 69, 19));
        chatWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(chatWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 750, 25));
        chatWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(chatWindow);
        statusbar->setObjectName("statusbar");
        chatWindow->setStatusBar(statusbar);

        retranslateUi(chatWindow);

        QMetaObject::connectSlotsByName(chatWindow);
    } // setupUi

    void retranslateUi(QMainWindow *chatWindow)
    {
        chatWindow->setWindowTitle(QCoreApplication::translate("chatWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("chatWindow", "chat", nullptr));
    } // retranslateUi

};

namespace Ui {
    class chatWindow: public Ui_chatWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATWINDOW_H
