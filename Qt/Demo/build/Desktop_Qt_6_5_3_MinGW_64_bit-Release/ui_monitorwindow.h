/********************************************************************************
** Form generated from reading UI file 'monitorwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MONITORWINDOW_H
#define UI_MONITORWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_monitorWindow
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *statusLabel;
    QLabel *modeLabel;
    QLabel *colorLabel;
    QLineEdit *showModeEdit;
    QLineEdit *showColorEdit;
    QLineEdit *showStatusEdit;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *monitorWindow)
    {
        if (monitorWindow->objectName().isEmpty())
            monitorWindow->setObjectName("monitorWindow");
        monitorWindow->resize(750, 500);
        centralwidget = new QWidget(monitorWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(80, 60, 301, 221));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        statusLabel = new QLabel(gridLayoutWidget);
        statusLabel->setObjectName("statusLabel");
        statusLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(statusLabel, 0, 0, 1, 1);

        modeLabel = new QLabel(gridLayoutWidget);
        modeLabel->setObjectName("modeLabel");
        modeLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(modeLabel, 2, 0, 1, 1);

        colorLabel = new QLabel(gridLayoutWidget);
        colorLabel->setObjectName("colorLabel");
        colorLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(colorLabel, 1, 0, 1, 1);

        showModeEdit = new QLineEdit(gridLayoutWidget);
        showModeEdit->setObjectName("showModeEdit");
        showModeEdit->setReadOnly(true);

        gridLayout->addWidget(showModeEdit, 2, 1, 1, 1);

        showColorEdit = new QLineEdit(gridLayoutWidget);
        showColorEdit->setObjectName("showColorEdit");
        showColorEdit->setReadOnly(true);

        gridLayout->addWidget(showColorEdit, 1, 1, 1, 1);

        showStatusEdit = new QLineEdit(gridLayoutWidget);
        showStatusEdit->setObjectName("showStatusEdit");
        showStatusEdit->setFrame(true);
        showStatusEdit->setReadOnly(true);
        showStatusEdit->setCursorMoveStyle(Qt::LogicalMoveStyle);
        showStatusEdit->setClearButtonEnabled(false);

        gridLayout->addWidget(showStatusEdit, 0, 1, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(80, 20, 650, 50));
        monitorWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(monitorWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 750, 25));
        monitorWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(monitorWindow);
        statusbar->setObjectName("statusbar");
        monitorWindow->setStatusBar(statusbar);

        retranslateUi(monitorWindow);

        QMetaObject::connectSlotsByName(monitorWindow);
    } // setupUi

    void retranslateUi(QMainWindow *monitorWindow)
    {
        monitorWindow->setWindowTitle(QCoreApplication::translate("monitorWindow", "MainWindow", nullptr));
        statusLabel->setText(QCoreApplication::translate("monitorWindow", "\345\267\245\344\275\234\347\212\266\346\200\201\357\274\232", nullptr));
        modeLabel->setText(QCoreApplication::translate("monitorWindow", "\346\250\241\345\274\217\357\274\232", nullptr));
        colorLabel->setText(QCoreApplication::translate("monitorWindow", "\351\242\234\350\211\262\357\274\232", nullptr));
        label->setText(QCoreApplication::translate("monitorWindow", "\350\257\264\346\230\216\357\274\232\347\233\221\346\216\247\346\250\241\345\274\217\357\274\214\345\217\257\344\273\245\346\237\245\347\234\213ESP32\346\235\277\350\275\275WS2812\347\232\204\345\267\245\344\275\234\347\212\266\346\200\201\357\274\214\351\242\234\350\211\262\357\274\214\346\250\241\345\274\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class monitorWindow: public Ui_monitorWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MONITORWINDOW_H
