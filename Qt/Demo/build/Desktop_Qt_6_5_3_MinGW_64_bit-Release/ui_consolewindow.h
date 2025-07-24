/********************************************************************************
** Form generated from reading UI file 'consolewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONSOLEWINDOW_H
#define UI_CONSOLEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_consoleWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *colorLabel;
    QLabel *statusLabel;
    QLabel *modeLabel;
    QComboBox *statusComboBox;
    QComboBox *colorComboBox;
    QComboBox *modeComboBox;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *consoleWindow)
    {
        if (consoleWindow->objectName().isEmpty())
            consoleWindow->setObjectName("consoleWindow");
        consoleWindow->resize(750, 500);
        centralwidget = new QWidget(consoleWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(80, 20, 650, 50));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(-68, 60, 441, 221));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        colorLabel = new QLabel(gridLayoutWidget);
        colorLabel->setObjectName("colorLabel");
        colorLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(colorLabel, 1, 0, 1, 1);

        statusLabel = new QLabel(gridLayoutWidget);
        statusLabel->setObjectName("statusLabel");
        statusLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(statusLabel, 0, 0, 1, 1);

        modeLabel = new QLabel(gridLayoutWidget);
        modeLabel->setObjectName("modeLabel");
        modeLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(modeLabel, 2, 0, 1, 1);

        statusComboBox = new QComboBox(gridLayoutWidget);
        statusComboBox->addItem(QString());
        statusComboBox->addItem(QString());
        statusComboBox->setObjectName("statusComboBox");

        gridLayout->addWidget(statusComboBox, 0, 1, 1, 1);

        colorComboBox = new QComboBox(gridLayoutWidget);
        colorComboBox->addItem(QString());
        colorComboBox->addItem(QString());
        colorComboBox->addItem(QString());
        colorComboBox->setObjectName("colorComboBox");
        colorComboBox->setEnabled(false);

        gridLayout->addWidget(colorComboBox, 1, 1, 1, 1);

        modeComboBox = new QComboBox(gridLayoutWidget);
        modeComboBox->addItem(QString());
        modeComboBox->addItem(QString());
        modeComboBox->setObjectName("modeComboBox");
        modeComboBox->setEnabled(false);

        gridLayout->addWidget(modeComboBox, 2, 1, 1, 1);

        consoleWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(consoleWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 750, 25));
        consoleWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(consoleWindow);
        statusbar->setObjectName("statusbar");
        consoleWindow->setStatusBar(statusbar);

        retranslateUi(consoleWindow);

        QMetaObject::connectSlotsByName(consoleWindow);
    } // setupUi

    void retranslateUi(QMainWindow *consoleWindow)
    {
        consoleWindow->setWindowTitle(QCoreApplication::translate("consoleWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("consoleWindow", "\350\257\264\346\230\216\357\274\232\346\216\247\345\210\266\345\217\260\346\250\241\345\274\217\357\274\214\345\217\257\344\273\245\346\216\247\345\210\266ESP32\346\235\277\350\275\275WS2812\347\232\204\345\267\245\344\275\234\347\212\266\346\200\201\357\274\214\351\242\234\350\211\262\357\274\214\346\250\241\345\274\217", nullptr));
        colorLabel->setText(QCoreApplication::translate("consoleWindow", "\351\242\234\350\211\262\357\274\232", nullptr));
        statusLabel->setText(QCoreApplication::translate("consoleWindow", "\345\267\245\344\275\234\347\212\266\346\200\201\357\274\232", nullptr));
        modeLabel->setText(QCoreApplication::translate("consoleWindow", "\346\250\241\345\274\217\357\274\232", nullptr));
        statusComboBox->setItemText(0, QCoreApplication::translate("consoleWindow", "Off", nullptr));
        statusComboBox->setItemText(1, QCoreApplication::translate("consoleWindow", "On", nullptr));

        colorComboBox->setItemText(0, QCoreApplication::translate("consoleWindow", "Red", nullptr));
        colorComboBox->setItemText(1, QCoreApplication::translate("consoleWindow", "Green", nullptr));
        colorComboBox->setItemText(2, QCoreApplication::translate("consoleWindow", "Blue", nullptr));

        modeComboBox->setItemText(0, QCoreApplication::translate("consoleWindow", "Constant light mode", nullptr));
        modeComboBox->setItemText(1, QCoreApplication::translate("consoleWindow", "Flashing mode", nullptr));

    } // retranslateUi

};

namespace Ui {
    class consoleWindow: public Ui_consoleWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONSOLEWINDOW_H
