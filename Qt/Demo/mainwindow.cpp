#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtCore/QDateTime>
#include <QtMqtt/QMqttClient>
#include <QtWidgets/QMessageBox>

/**
 * @brief 主窗口构造函数
 * @param parent 父窗口指针
 * @note 初始化UI和窗口间信号连接
 */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 添加子窗口到堆栈
    ui->stackedWidget->addWidget(&connectionwnd);
    ui->stackedWidget->addWidget(&monitorwnd);
    ui->stackedWidget->addWidget(&consolewnd);

    // 设置按钮分组
    btnGroup.addButton(ui->connectionButton, 0);
    btnGroup.addButton(ui->monitorButton, 1);
    btnGroup.addButton(ui->consoleButton, 2);

    // 连接按钮组信号
    connect(&btnGroup,
            &QButtonGroup::idClicked,
            ui->stackedWidget,
            &QStackedWidget::setCurrentIndex);

    // 连接MQTT消息接收信号
    connect(&connectionwnd,
            &connectionWindow::newMessageReceived,
            &monitorwnd,
            &monitorWindow::handleMQTTMessage);

    // 连接控制命令信号
    connect(&consolewnd,
            &consoleWindow::controlCommand,
            &connectionwnd,
            &connectionWindow::publishControlCommand);

    // 设置默认选中的页面
    btnGroup.button(0)->setChecked(true);
    ui->stackedWidget->setCurrentIndex(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief 最小化窗口
 */
void MainWindow::on_toolButton_min_clicked()
{
    this->showMinimized();  // 最小化窗口
}

/**
 * @brief 关闭窗口
 */
void MainWindow::on_toolButton_close_clicked()
{
    this->close();  // 退出应用程序
}
//实际上我没有发现这两个函数有什么用，但是删除会报错
