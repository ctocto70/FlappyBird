#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QKeyEvent>
#include "tubes.h"
#include "bird.h"

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
    const int speed = 25;
    Tubes* tubes;
    Bird* bird;
    QTimer *timer;
    QImage* image;
    QRect* rect;
private slots:
    void slotTimerAlarm();
protected:
    virtual void keyPressEvent(QKeyEvent *event);
};
#endif // MAINWINDOW_H
