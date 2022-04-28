#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QPainter>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(window_width, window_heigth);
    image = new QImage("C:\\QtProjects\\FlappyBird\\Background.png", "PNG");
    rect = new QRect(0, 0, window_width, window_heigth);


    tubes = new Tubes(window_width, window_heigth);
    bird = new Bird();
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(slotTimerAlarm()));
    timer->start(speed); // И запустим таймер
}

MainWindow::~MainWindow()
{
    delete ui;
    delete tubes;
    delete timer;
    delete image;
    delete rect;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter* painter = new QPainter(this);
    painter->drawImage(*rect, *image);
    tubes->paint_(painter);
    bird->paint_(painter);
    delete painter;
}

void MainWindow::slotTimerAlarm() {
    repaint();
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    if(event->key() == Qt::Key_Space) {
        bird->jump();
    }
}

