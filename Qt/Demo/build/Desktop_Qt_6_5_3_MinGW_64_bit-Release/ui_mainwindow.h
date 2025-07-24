/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *sideBar_2;
    QGridLayout *sideBar;
    QToolButton *monitorButton;
    QToolButton *connectionButton;
    QToolButton *consoleButton;
    QStackedWidget *stackedWidget;
    QMenuBar *menubar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(750, 555);
        MainWindow->setStyleSheet(QString::fromUtf8("/* \351\273\230\350\256\244 */\n"
"QToolButton{   \n"
"	border-top: 3px outset transparent;           /* \344\270\212\350\276\271\346\241\206\345\256\275\345\272\2463\345\203\217\347\264\240\343\200\201\347\252\201\345\207\272\346\230\276\347\244\272\343\200\201\351\242\234\350\211\262\344\270\272\351\200\217\346\230\216 */\n"
"	border-bottom: 7px outset transparent;\n"
"	border-right: 3px outset transparent;\n"
"	border-left: 3px outset transparent;\n"
"    min-width: 80px;                            /* \346\216\247\344\273\266\346\234\200\345\260\217\345\256\275\345\272\246 */\n"
"    min-height: 80px;\n"
"	background-color: rgb(228, 228, 228);\n"
"}\n"
"\n"
"/* \351\274\240\346\240\207\346\202\254\345\201\234 */\n"
"QToolButton:hover{\n"
"	background-color: rgb(205, 205, 205);\n"
"}\n"
"\n"
"/* \347\202\271\345\207\273\345\222\214\346\214\211\344\270\213 */\n"
"QToolButton:pressed,QToolButton:checked{\n"
"	border-left: 3px outset rgb(93, 95, 97); /* \345\267\246\350\276\271\346\241\206\345\256\275\345\272\246"
                        "3\345\203\217\347\264\240\343\200\201\347\252\201\345\207\272\346\230\276\347\244\272\343\200\201\351\242\234\350\211\262\344\270\272\346\267\261\346\267\261\347\201\260 */\n"
"	background-color: rgb(246, 246, 246);\n"
"}\n"
"\n"
"QPushButton:default {\n"
"    border-color: navy; /* make the default button prominent */\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setAutoFillBackground(false);
        sideBar_2 = new QWidget(centralwidget);
        sideBar_2->setObjectName("sideBar_2");
        sideBar_2->setGeometry(QRect(0, 0, 171, 521));
        sideBar = new QGridLayout(sideBar_2);
        sideBar->setSpacing(0);
        sideBar->setObjectName("sideBar");
        sideBar->setContentsMargins(0, 0, 0, 0);
        monitorButton = new QToolButton(sideBar_2);
        monitorButton->setObjectName("monitorButton");
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(monitorButton->sizePolicy().hasHeightForWidth());
        monitorButton->setSizePolicy(sizePolicy);
        monitorButton->setStyleSheet(QString::fromUtf8("/* \351\273\230\350\256\244 */\n"
"QToolButton{   \n"
"	border-top: 3px outset transparent;           /* \344\270\212\350\276\271\346\241\206\345\256\275\345\272\2463\345\203\217\347\264\240\343\200\201\347\252\201\345\207\272\346\230\276\347\244\272\343\200\201\351\242\234\350\211\262\344\270\272\351\200\217\346\230\216 */\n"
"	border-bottom: 7px outset transparent;\n"
"	border-right: 3px outset transparent;\n"
"	border-left: 3px outset transparent;\n"
"    min-width: 80px;                            /* \346\216\247\344\273\266\346\234\200\345\260\217\345\256\275\345\272\246 */\n"
"    min-height: 80px;\n"
"	background-color: rgb(228, 228, 228);\n"
"}\n"
"\n"
"/* \351\274\240\346\240\207\346\202\254\345\201\234 */\n"
"QToolButton:hover{\n"
"	background-color: rgb(205, 205, 205);\n"
"}\n"
"\n"
"/* \347\202\271\345\207\273\345\222\214\346\214\211\344\270\213 */\n"
"QToolButton:pressed,QToolButton:checked{\n"
"	border-left: 3px outset rgb(93, 95, 97); /* \345\267\246\350\276\271\346\241\206\345\256\275\345\272\246"
                        "3\345\203\217\347\264\240\343\200\201\347\252\201\345\207\272\346\230\276\347\244\272\343\200\201\351\242\234\350\211\262\344\270\272\346\267\261\346\267\261\347\201\260 */\n"
"	background-color: rgb(246, 246, 246);\n"
"}\n"
"\n"
"QPushButton:default {\n"
"    border-color: navy; /* make the default button prominent */\n"
"}"));
        monitorButton->setCheckable(true);
        monitorButton->setAutoExclusive(true);

        sideBar->addWidget(monitorButton, 1, 0, 1, 1);

        connectionButton = new QToolButton(sideBar_2);
        connectionButton->setObjectName("connectionButton");
        sizePolicy.setHeightForWidth(connectionButton->sizePolicy().hasHeightForWidth());
        connectionButton->setSizePolicy(sizePolicy);
        connectionButton->setCheckable(true);
        connectionButton->setAutoExclusive(true);
        connectionButton->setToolButtonStyle(Qt::ToolButtonTextOnly);
        connectionButton->setAutoRaise(false);
        connectionButton->setArrowType(Qt::NoArrow);

        sideBar->addWidget(connectionButton, 0, 0, 1, 1);

        consoleButton = new QToolButton(sideBar_2);
        consoleButton->setObjectName("consoleButton");
        sizePolicy.setHeightForWidth(consoleButton->sizePolicy().hasHeightForWidth());
        consoleButton->setSizePolicy(sizePolicy);
        consoleButton->setStyleSheet(QString::fromUtf8("/* \351\273\230\350\256\244 */\n"
"QToolButton{   \n"
"	border-top: 3px outset transparent;           /* \344\270\212\350\276\271\346\241\206\345\256\275\345\272\2463\345\203\217\347\264\240\343\200\201\347\252\201\345\207\272\346\230\276\347\244\272\343\200\201\351\242\234\350\211\262\344\270\272\351\200\217\346\230\216 */\n"
"	border-bottom: 7px outset transparent;\n"
"	border-right: 3px outset transparent;\n"
"	border-left: 3px outset transparent;\n"
"    min-width: 80px;                            /* \346\216\247\344\273\266\346\234\200\345\260\217\345\256\275\345\272\246 */\n"
"    min-height: 80px;\n"
"	background-color: rgb(228, 228, 228);\n"
"}\n"
"\n"
"/* \351\274\240\346\240\207\346\202\254\345\201\234 */\n"
"QToolButton:hover{\n"
"	background-color: rgb(205, 205, 205);\n"
"}\n"
"\n"
"/* \347\202\271\345\207\273\345\222\214\346\214\211\344\270\213 */\n"
"QToolButton:pressed,QToolButton:checked{\n"
"	border-left: 3px outset rgb(93, 95, 97); /* \345\267\246\350\276\271\346\241\206\345\256\275\345\272\246"
                        "3\345\203\217\347\264\240\343\200\201\347\252\201\345\207\272\346\230\276\347\244\272\343\200\201\351\242\234\350\211\262\344\270\272\346\267\261\346\267\261\347\201\260 */\n"
"	background-color: rgb(246, 246, 246);\n"
"}\n"
"\n"
"QPushButton:default {\n"
"    border-color: navy; /* make the default button prominent */\n"
"}"));
        consoleButton->setCheckable(true);
        consoleButton->setAutoExclusive(true);

        sideBar->addWidget(consoleButton, 2, 0, 1, 1);

        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(170, 4, 941, 521));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 750, 25));
        MainWindow->setMenuBar(menubar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        monitorButton->setText(QCoreApplication::translate("MainWindow", "Monitor", nullptr));
        connectionButton->setText(QCoreApplication::translate("MainWindow", "  Connection", nullptr));
        consoleButton->setText(QCoreApplication::translate("MainWindow", "Console", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
