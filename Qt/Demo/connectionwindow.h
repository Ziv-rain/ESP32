#ifndef CONNECTIONWINDOW_H
#define CONNECTIONWINDOW_H

#include "qmqttclient.h"
#include <QMainWindow>

namespace Ui {
class connectionWindow;
}

class connectionWindow : public QMainWindow
{
    Q_OBJECT

//consolewindow
public slots:
    void publishControlCommand(const QString &topic, const QString &message);

public:
    explicit connectionWindow(QWidget *parent = nullptr);
    ~connectionWindow();

//connectwindow
private slots:
    void connectButton_clicked();
    void disconnectButton_clicked();
    void updateConnectionState();
    void handleError(QMqttClient::ClientError error);  // 添加错误处理函数
   // void checkConnectionState(); // 连接状态检查函数
    void clearSubscriptions();


    void subscribeButton_clicked();
    void handleMessageReceived(const QString &topic, const QMqttMessage &msg);
    void showContextMenu(const QPoint &pos);


private:
    Ui::connectionWindow *ui;

    void resetUIState();     //重置函数
    void resetClientState(); // 重置函数
    void deleteSelectedItem();//删除主题函数

    //QTimer *connectionCheckTimer; // 连接检查定时器


    QMqttClient *client;

    bool isConnecting; // 连接状态标志
    bool isActiveDisconnect;      // 标记是否为主动断开

signals:
    void newMessageReceived(const QString &topic, const QString &message);  //消息接收信号


};

#endif // CONNECTIONWINDOW_H
