#include "monitorwindow.h"
#include "ui_monitorwindow.h"
#include <QJsonDocument>
#include <QJsonObject>

/**
 * @brief 监控窗口构造函数
 * @param parent 父窗口指针
 */
monitorWindow::monitorWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::monitorWindow)
{
    ui->setupUi(this);

}

monitorWindow::~monitorWindow()
{
    delete ui;
}

/**
 * @brief 处理MQTT消息
 * @param topic 消息主题
 * @param message 消息内容
 * @note 更新LED状态显示界面
 */
void monitorWindow::handleMQTTMessage(const QString &topic, const QString &message)
{
    if(topic == "ESP32/LED/Report") {
        QJsonDocument doc = QJsonDocument::fromJson(message.toUtf8());
        QJsonObject obj = doc.object();

        QString mode = obj["mode"].toString();
        QString color = obj["color"].toString();
        QString power = obj["power"].toString();

        if(power == "Off")
        {
            ui->showColorEdit->setEnabled(false);
            ui->showModeEdit->setEnabled(false);
            ui->showStatusEdit->setText(power);
        }
        else
        {
            ui->showColorEdit->setEnabled(true);
            ui->showModeEdit->setEnabled(true);
            // 更新UI元素
            ui->showStatusEdit->setText(power);
            ui->showColorEdit->setText(color);
            ui->showModeEdit->setText(mode);
        }
    }
}

