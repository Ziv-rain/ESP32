#ifndef MONITORWINDOW_H
#define MONITORWINDOW_H

#include <QMainWindow>

namespace Ui {
class monitorWindow;
}

class monitorWindow : public QMainWindow
{
    Q_OBJECT

public slots:
    void handleMQTTMessage(const QString &topic, const QString &message);

public:
    explicit monitorWindow(QWidget *parent = nullptr);
    ~monitorWindow();

private slots:


private:
    Ui::monitorWindow *ui;
};

#endif // MONITORWINDOW_H
