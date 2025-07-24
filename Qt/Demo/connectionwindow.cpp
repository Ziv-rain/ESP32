#include "connectionwindow.h"
#include "ui_connectionwindow.h"

#include <QtCore/QDateTime>
#include <QtMqtt/QMqttClient>
#include <QtWidgets/QMessageBox>
#include <QDebug>

/**
 * @brief 连接窗口构造函数
 * @param parent 父窗口指针
 * @note 初始化MQTT客户端和UI连接
 */
connectionWindow::connectionWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::connectionWindow)
    , isConnecting(false) // 初始化状态标志
    , isActiveDisconnect(false)
{
    ui->setupUi(this);
    client = new QMqttClient(this);  // 初始化成员变量

    // 连接按钮信号
    connect(ui->connectButton,
            SIGNAL(clicked()),
            this,
            SLOT(connectButton_clicked()));
    connect(ui->disconnectButton,
            SIGNAL(clicked()),
            this,
            SLOT(disconnectButton_clicked()));
    connect(ui->subscribeButton,
            SIGNAL(clicked()),
            this,
            SLOT(subscribeButton_clicked()));

    // 使用 lambda 表达式处理错误信号
    connect(client,
            &QMqttClient::errorChanged,
            this,
            [this](QMqttClient::ClientError error)
            {
           // 只有在尝试连接时才处理错误
                if (isConnecting)
                {
                     this->handleError(error);
                }
            });

    //处理状态变化
    connect(client,
            &QMqttClient::stateChanged,
            this,
            &connectionWindow::updateConnectionState);


    // 添加列表控件的右键菜单支持
    ui->topicListWidget->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->topicListWidget,
            &QListWidget::customContextMenuRequested,
            this,
            &connectionWindow::showContextMenu);
}

connectionWindow::~connectionWindow()
{
    delete ui;
}

/**
 * @brief 连接按钮点击处理
 * @note 连接MQTT服务器
 */
void connectionWindow::connectButton_clicked()
{
    resetClientState();// 重置连接状态
    isConnecting = true;
    //获取文本框信息
    QString Username =  ui->nameEdit->text();
    QString Hostname =  ui->localEdit->text();
    QString Port =  ui->portEdit->text();
    QString ClientID =  ui->ClientIDEdit->text();

    //设置连接信息
    client->setUsername(Username);  //设置你的用户名
    client->setHostname(Hostname);  //设置你的broker地址
    client->setPort(Port.toInt());  //设置你的MQTT端口
    client->setClientId(ClientID);  //设置你的ClinetID

    if(Hostname.isEmpty() || Port.isEmpty()) {
        QMessageBox::warning(this, "输入错误", "主机地址和端口不能为空");
        isConnecting = false; // 重置状态
        return;
    }

    //连接服务器
    client->connectToHost();

    //调试用
    // qDebug()<<Username<<" "<<Hostname<<""<<Port<<" "<<ClientID;
    // qDebug() << "当前状态：" << client->state();
}

/**
 * @brief 清空所有订阅
 */
void connectionWindow::clearSubscriptions()
{
    // 取消所有订阅
    for (int i = 0; i < ui->topicListWidget->count(); i++) {
        QString topic = ui->topicListWidget->item(i)->text();
        client->unsubscribe(topic);
    }

    // 清空列表
    ui->topicListWidget->clear();
}

/**
 * @brief 断开连接按钮处理
 * @note 断开MQTT连接并重置UI
 */
void connectionWindow::disconnectButton_clicked()
{
    isActiveDisconnect = true; // 标记为主动断开
    client->disconnectFromHost();

    // 清空订阅列表
    clearSubscriptions();

    // 恢复UI状态
    ui->connectButton->setEnabled(true);
    ui->nameEdit->setEnabled(true);
    ui->portEdit->setEnabled(true);
    ui->ClientIDEdit->setEnabled(true);
    ui->localEdit->setEnabled(true);
    ui->disconnectButton->setEnabled(false);
    ui->topicEdit->setEnabled(false);
    ui->topicListLabel->setEnabled(false);
    ui->subscribeButton->setEnabled(false);
}

/**
 * @brief 更新MQTT连接状态
 * @note 根据客户端状态更新UI元素使能状态
 */
void connectionWindow::updateConnectionState()
{
    if (client->state() == QMqttClient::Connected)
    {
        isConnecting = false;

        ui->connectButton->setEnabled(false);
        ui->nameEdit->setEnabled(false);
        ui->portEdit->setEnabled(false);
        ui->ClientIDEdit->setEnabled(false);
        ui->localEdit->setEnabled(false);
        ui->disconnectButton->setEnabled(true);
        ui->topicEdit->setEnabled(true);
        ui->topicListLabel->setEnabled(true);
        ui->subscribeButton->setEnabled(true);
    }
    else if (client->state() == QMqttClient::Disconnected && !isActiveDisconnect) {
        QMessageBox::warning(this, "连接断开", "与服务器的连接已断开");
        clearSubscriptions();
        resetUIState();
    }

    isActiveDisconnect = false; // 重置标记
}

/**
 * @brief 处理MQTT客户端错误
 * @param error 错误代码
 * @note 根据错误类型显示相应警告信息
 */
void connectionWindow::handleError(QMqttClient::ClientError error)
{
    // 只在连接过程中处理错误
    if (!isConnecting) return;

    QString errorMessage;
    switch (error) {
    case QMqttClient::TransportInvalid:
        errorMessage = "网络连接错误";
        break;
    default:
        errorMessage = "未知连接错误";
    }

    QMessageBox::critical(this, "连接失败", "连接服务器失败: " + errorMessage);

    // 完全重置连接状态
    isConnecting = false;
    // 恢复UI状态
    resetUIState();
}

/**
 * @brief 重置UI状态
 * @note 将界面控件恢复为可连接状态
 */
void connectionWindow::resetUIState()
{
    ui->connectButton->setEnabled(true);
    ui->nameEdit->setEnabled(true);
    ui->portEdit->setEnabled(true);
    ui->ClientIDEdit->setEnabled(true);
    ui->localEdit->setEnabled(true);
    ui->disconnectButton->setEnabled(false);
    ui->topicEdit->setEnabled(false);
    ui->topicListLabel->setEnabled(false);
    ui->subscribeButton->setEnabled(false);
}

/**
 * @brief 重置MQTT客户端状态
 * @note 创建新的MQTT客户端实例并重置连接状态
 */
void connectionWindow::resetClientState()
{
    // 如果客户端处于连接状态，先断开
    if (client->state() != QMqttClient::Disconnected) {
        client->disconnectFromHost();
    }

    // 删除现有客户端
    client->deleteLater();

    // 创建新的客户端实例
    client = new QMqttClient(this);

    // 重新连接信号
    connect(client, &QMqttClient::stateChanged, this, &connectionWindow::updateConnectionState);
    connect(client, &QMqttClient::errorChanged, this, &connectionWindow::handleError);

    // 重置状态标志
    isConnecting = false;

    // 清空订阅
    clearSubscriptions();
}

/**
 * @brief 订阅按钮点击处理
 * @note 订阅指定主题并添加到订阅列表
 */
void connectionWindow::subscribeButton_clicked()
{
    QString Topic =  ui->topicEdit->text();

    if(Topic.isEmpty()) return;
    //qDebug() << Topic;

    // 检查是否已存在相同的主题
    bool isExists = false;
    for(int i = 0; i < ui->topicListWidget->count(); ++i) {
        if(ui->topicListWidget->item(i)->text() == Topic) {
            isExists = true;
            break;
        }
    }

    if(isExists) {
        // 可选：提示用户或打日志
        qDebug() << "订阅主题已存在：" << Topic;
        QMessageBox::information(this, "重复主题", "该主题已订阅");
        return;
    }

    ui->topicListWidget->addItem(Topic);       // 添加到列表

    // 通过mqtt客户端对象订阅
    if(client && client->state() == QMqttClient::Connected)
    {
        auto subscription = client->subscribe(Topic, 0);
        if(!subscription)
        {
            qDebug() << "订阅失败：" << Topic;
        }
        else
        {
            // 关联订阅信号
            connect(subscription,
                    &QMqttSubscription::messageReceived,
                    this,
                    [this, Topic](QMqttMessage msg)
                    {
                        this->handleMessageReceived(Topic, msg);
                    }
                    );
        }
    }
}

/**
 * @brief 处理接收到的MQTT消息
 * @param topic 消息主题
 * @param msg MQTT消息对象
 * @note 将消息内容转发给监控窗口
 */
void connectionWindow::handleMessageReceived(const QString &topic, const QMqttMessage &msg)
{
    QString payload = QString::fromUtf8(msg.payload());

    // 调试输出
    qDebug() << "Received message: [" << topic << "]" << payload;

    // 发出信号通知其他窗口
    emit newMessageReceived(topic, payload);
}

/**
 * @brief 显示主题列表的右键菜单
 * @param pos 鼠标点击位置
 * @note 在指定位置显示包含删除操作的上下文菜单
 */
void connectionWindow::showContextMenu(const QPoint &pos)
{
    QPoint globalPos = ui->topicListWidget->mapToGlobal(pos);

    // 创建右键菜单
    QMenu contextMenu(tr("操作"), this);

    // 添加删除动作
    QAction* deleteAction = contextMenu.addAction(tr("删除"));

    // 如果没有选中项，禁用删除按钮
    if(ui->topicListWidget->selectedItems().isEmpty()) {
        deleteAction->setEnabled(false);
    }

    // 执行菜单并处理选择
    QAction* selectedAction = contextMenu.exec(globalPos);
    if(selectedAction == deleteAction) {
        deleteSelectedItem();
    }
}

/**
 * @brief 删除选中的主题项
 * @note 从列表中移除选中的主题并取消对应订阅
 */
void connectionWindow::deleteSelectedItem()
{
    // 获取所有选中的项目
    QList<QListWidgetItem*> selectedItems = ui->topicListWidget->selectedItems();

    foreach (QListWidgetItem* item, selectedItems) {
        QString topic = item->text();

        // 取消MQTT订阅
        if(client && client->state() == QMqttClient::Connected) {
            client->unsubscribe(topic);
        }

        // 从列表控件中移除
        int row = ui->topicListWidget->row(item);
        QListWidgetItem* removedItem = ui->topicListWidget->takeItem(row);
        delete removedItem; // 重要：删除对象释放内存
    }
}

/**
 * @brief 发布控制命令到MQTT代理
 * @param topic 目标主题
 * @param message 要发布的消息内容
 * @note 当客户端连接时发布消息，否则显示警告
 */
void connectionWindow::publishControlCommand(const QString &topic, const QString &message)
{
    if(client && client->state() == QMqttClient::Connected) {
        qDebug() << "Publishing to" << topic << ":" << message;
        client->publish(topic, message.toUtf8());
    } else {
        qDebug() << "MQTT client not connected, cannot publish";
        QMessageBox::warning(this, "发布失败", "MQTT连接未建立，无法发送控制命令");
    }
}

