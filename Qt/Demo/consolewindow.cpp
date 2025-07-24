#include "consolewindow.h"
#include "ui_consolewindow.h"

#include <QJsonObject>
#include <QJsonDocument>
#include <QDebug>

/**
 * @brief 控制台窗口构造函数
 * @param parent 父窗口指针
 * @note 初始化UI和默认状态值
 */
consoleWindow::consoleWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::consoleWindow)
    , currentStatus("Off")  // 默认关闭状态
    , currentColor("Red")  // 默认红色
    , currentMode("Constant light mode") // 默认常亮模式
{
    ui->setupUi(this);

    // 连接组合框信号
    connect(ui->statusComboBox,
            QOverload<int>::of(&QComboBox::currentIndexChanged),
            this,
            &consoleWindow::onStatusChanged);

    connect(ui->colorComboBox,
            QOverload<int>::of(&QComboBox::currentIndexChanged),
            this,
            &consoleWindow::onColorChanged);

    connect(ui->modeComboBox,
            QOverload<int>::of(&QComboBox::currentIndexChanged),
            this,
            &consoleWindow::onModeChanged);
}

consoleWindow::~consoleWindow()
{
    delete ui;
}

/**
 * @brief 处理状态组合框变更
 * @param index 当前选中项的索引
 * @note 更新当前状态值并发送控制命令
 */
void consoleWindow::onStatusChanged(int index)
{
    currentStatus = ui->statusComboBox->itemText(index);
    if(currentStatus == "Off")
    {
        ui->colorComboBox->setEnabled(false);
        ui->modeComboBox->setEnabled(false);
    }
    else
    {
        ui->colorComboBox->setEnabled(true);
        ui->modeComboBox->setEnabled(true);
    }
    sendControlCommand();
}

/**
 * @brief 处理颜色组合框变更
 * @param index 当前选中项的索引
 * @note 更新当前颜色值并发送控制命令
 */
void consoleWindow::onColorChanged(int index)
{
    currentColor = ui->colorComboBox->itemText(index);
    sendControlCommand();
}

/**
 * @brief 处理模式组合框变更
 * @param index 当前选中项的索引
 * @note 更新当前模式值并发送控制命令
 */
void consoleWindow::onModeChanged(int index)
{
    currentMode = ui->modeComboBox->itemText(index);
    sendControlCommand();
}

/**
 * @brief 发送控制命令到MQTT
 * @note 创建包含当前状态的JSON对象并通过信号发送
 */
void consoleWindow::sendControlCommand()
{
    // 创建JSON对象
    QJsonObject controlObj;
    controlObj["power"] = currentStatus;
    controlObj["color"] = currentColor;
    controlObj["mode"] = currentMode;

    // 转换为JSON文档
    QJsonDocument doc(controlObj);
    QString message = doc.toJson(QJsonDocument::Compact);

    qDebug() << "Sending control command:" << message;

    // 发送控制信号
    emit controlCommand("ESP32/LED/Control", message);
}


