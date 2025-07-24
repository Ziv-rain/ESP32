#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QButtonGroup>

#include "connectionwindow.h"
#include "monitorwindow.h"
#include "consolewindow.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_toolButton_min_clicked();
    void on_toolButton_close_clicked();

private:
    Ui::MainWindow *ui;

    QButtonGroup btnGroup;

    connectionWindow connectionwnd;
    monitorWindow monitorwnd;
    consoleWindow consolewnd;
};
#endif // MAINWINDOW_H
