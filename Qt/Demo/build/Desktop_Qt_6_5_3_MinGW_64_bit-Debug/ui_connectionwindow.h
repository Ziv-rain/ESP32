/********************************************************************************
** Form generated from reading UI file 'connectionwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNECTIONWINDOW_H
#define UI_CONNECTIONWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_connectionWindow
{
public:
    QWidget *centralwidget;
    QPushButton *connectButton;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *nameLabel;
    QLineEdit *nameEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *localLabel;
    QLineEdit *localEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *portLabel;
    QLineEdit *portEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *ClientIDlabel;
    QLineEdit *ClientIDEdit;
    QPushButton *disconnectButton;
    QPushButton *subscribeButton;
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *topicLabel;
    QLineEdit *topicEdit;
    QVBoxLayout *verticalLayout_2;
    QLabel *topicListLabel;
    QListWidget *topicListWidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *connectionWindow)
    {
        if (connectionWindow->objectName().isEmpty())
            connectionWindow->setObjectName("connectionWindow");
        connectionWindow->resize(750, 500);
        connectionWindow->setAcceptDrops(false);
        centralwidget = new QWidget(connectionWindow);
        centralwidget->setObjectName("centralwidget");
        connectButton = new QPushButton(centralwidget);
        connectButton->setObjectName("connectButton");
        connectButton->setGeometry(QRect(420, 21, 131, 81));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(40, 30, 311, 151));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        nameLabel = new QLabel(layoutWidget);
        nameLabel->setObjectName("nameLabel");

        horizontalLayout->addWidget(nameLabel);

        nameEdit = new QLineEdit(layoutWidget);
        nameEdit->setObjectName("nameEdit");

        horizontalLayout->addWidget(nameEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        localLabel = new QLabel(layoutWidget);
        localLabel->setObjectName("localLabel");

        horizontalLayout_2->addWidget(localLabel);

        localEdit = new QLineEdit(layoutWidget);
        localEdit->setObjectName("localEdit");

        horizontalLayout_2->addWidget(localEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        portLabel = new QLabel(layoutWidget);
        portLabel->setObjectName("portLabel");

        horizontalLayout_3->addWidget(portLabel);

        portEdit = new QLineEdit(layoutWidget);
        portEdit->setObjectName("portEdit");

        horizontalLayout_3->addWidget(portEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        ClientIDlabel = new QLabel(layoutWidget);
        ClientIDlabel->setObjectName("ClientIDlabel");

        horizontalLayout_4->addWidget(ClientIDlabel);

        ClientIDEdit = new QLineEdit(layoutWidget);
        ClientIDEdit->setObjectName("ClientIDEdit");

        horizontalLayout_4->addWidget(ClientIDEdit);


        verticalLayout->addLayout(horizontalLayout_4);

        disconnectButton = new QPushButton(centralwidget);
        disconnectButton->setObjectName("disconnectButton");
        disconnectButton->setEnabled(false);
        disconnectButton->setGeometry(QRect(420, 102, 131, 81));
        subscribeButton = new QPushButton(centralwidget);
        subscribeButton->setObjectName("subscribeButton");
        subscribeButton->setEnabled(false);
        subscribeButton->setGeometry(QRect(420, 240, 131, 61));
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(40, 240, 311, 225));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        topicLabel = new QLabel(widget);
        topicLabel->setObjectName("topicLabel");

        horizontalLayout_5->addWidget(topicLabel);

        topicEdit = new QLineEdit(widget);
        topicEdit->setObjectName("topicEdit");
        topicEdit->setEnabled(false);

        horizontalLayout_5->addWidget(topicEdit);


        verticalLayout_3->addLayout(horizontalLayout_5);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        topicListLabel = new QLabel(widget);
        topicListLabel->setObjectName("topicListLabel");

        verticalLayout_2->addWidget(topicListLabel);

        topicListWidget = new QListWidget(widget);
        topicListWidget->setObjectName("topicListWidget");
        topicListWidget->setEnabled(true);
        topicListWidget->setMouseTracking(false);
        topicListWidget->setAcceptDrops(true);

        verticalLayout_2->addWidget(topicListWidget);


        verticalLayout_3->addLayout(verticalLayout_2);

        connectionWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(connectionWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 750, 25));
        connectionWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(connectionWindow);
        statusbar->setObjectName("statusbar");
        connectionWindow->setStatusBar(statusbar);

        retranslateUi(connectionWindow);

        QMetaObject::connectSlotsByName(connectionWindow);
    } // setupUi

    void retranslateUi(QMainWindow *connectionWindow)
    {
        connectionWindow->setWindowTitle(QCoreApplication::translate("connectionWindow", "MainWindow", nullptr));
        connectButton->setText(QCoreApplication::translate("connectionWindow", "Connect", nullptr));
        nameLabel->setText(QCoreApplication::translate("connectionWindow", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        localLabel->setText(QCoreApplication::translate("connectionWindow", "\346\234\215\345\212\241\345\231\250\345\234\260\345\235\200\357\274\232", nullptr));
        portLabel->setText(QCoreApplication::translate("connectionWindow", "\347\253\257\345\217\243\357\274\232", nullptr));
        ClientIDlabel->setText(QCoreApplication::translate("connectionWindow", "Client ID\357\274\232", nullptr));
        disconnectButton->setText(QCoreApplication::translate("connectionWindow", "Disconnect", nullptr));
        subscribeButton->setText(QCoreApplication::translate("connectionWindow", "Subscribe", nullptr));
        topicLabel->setText(QCoreApplication::translate("connectionWindow", "Topic\357\274\232", nullptr));
        topicListLabel->setText(QCoreApplication::translate("connectionWindow", "Topic List:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class connectionWindow: public Ui_connectionWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECTIONWINDOW_H
