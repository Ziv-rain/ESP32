#ifndef CONSOLEWINDOW_H
#define CONSOLEWINDOW_H

#include <QMainWindow>

namespace Ui {
class consoleWindow;
}

/**
 * @brief 控制台窗口类
 * @note 提供LED控制界面，发送控制命令
 */
class consoleWindow : public QMainWindow
{
    Q_OBJECT

signals:
    /**
     * @brief 控制命令信号
     * @param topic MQTT主题
     * @param message 控制消息
     */
    void controlCommand(const QString &topic, const QString &message);

public:
    explicit consoleWindow(QWidget *parent = nullptr);
    ~consoleWindow();

private slots:
    void sendControlCommand();
    void onStatusChanged(int index);
    void onColorChanged(int index);
    void onModeChanged(int index);

private:
    Ui::consoleWindow *ui;

    // 添加组合框值跟踪变量
    QString currentStatus;
    QString currentColor;
    QString currentMode;
};

#endif // CONSOLEWINDOW_H
