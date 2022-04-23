#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "tubes.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void paintEvent(QPaintEvent *event);

private:
    Ui::MainWindow *ui;
    const int window_width = 480; // "length"
    const int window_heigth = 600;
    Tubes* tubes;
    QTimer *timer;
private slots:
    void slotTimerAlarm();
};
#endif // MAINWINDOW_H
