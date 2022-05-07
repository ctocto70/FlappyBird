#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QPainter>
#include <QPixmap>
#include<QDebug>

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
    timer_fall = new QTimer();
    IsFalling = 0;
    connect(timer, SIGNAL(timeout()), this, SLOT(slotTimerAlarm()));
    connect(timer_fall, SIGNAL(timeout()), this, SLOT(slotTimerFall()));
    timer->start(speed); // И запустим таймер
}

MainWindow::~MainWindow()
{
    delete ui;
    delete tubes;
    delete timer;
    delete timer_fall;
    delete image;
    delete rect;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter* painter = new QPainter(this);
    if(!IsFalling) {
        painter->drawImage(*rect, *image);
        tubes->paint_(painter);
        bird->paint_(painter);
    } else {
        painter->drawImage(*rect, *image);
        tubes->paint_fall_(painter);
        bird->paint_fall_(painter);
    }
    delete painter;
}

void MainWindow::slotTimerAlarm() {
    repaint();
    for(auto& i : tubes->getTubes()) {
        if(bird->getLeft() > i->getRight() && !(i->IsPassed())) {
            score++;
            qDebug() << score;
            i->pass();
        }
        if(bird->getRect()->intersects(*i->getTopTube())) {
            timer->stop();
            IsFalling = true;
            timer_fall->start(speed);
        }
        if(bird->getRect()->intersects(*i->getDownTube())) {
            timer->stop();
            IsFalling = true;
            timer_fall->start(speed);
        }
        if(i->getLeft() - bird->getLeft() < bird->getWidth() &&  bird->getLeft() < i->getRight() && bird->getTop() < 0) {
            timer->stop();
            IsFalling = true;
            timer_fall->start(speed);
        }
        if(bird->getBottom() >= window_heigth) {
            timer->stop();
            IsFalling = true;
        }
    }
}

void MainWindow::slotTimerFall() {
    repaint();
    if(bird->getBottom() >= window_heigth) {
        timer_fall->stop();
    }
}


void MainWindow::keyPressEvent(QKeyEvent *event) {
    if(!IsFalling) {
        if(event->key() == Qt::Key_Space) {
            bird->jump();
        }
    }
}


