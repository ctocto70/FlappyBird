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
    IsGame = 0;
    IsNewWindow = 1;
    connect(timer, SIGNAL(timeout()), this, SLOT(slotTimerAlarm()));
    connect(timer_fall, SIGNAL(timeout()), this, SLOT(slotTimerFall()));
    //timer->start(speed);
    lcd = new QLCDNumber(this);
    label = new QLabel(this);
    label->move(0, window_heigth / 2 - label_heigth / 2);
    label->resize(window_width, label_heigth);
    label->setAlignment(Qt::AlignCenter);
    QFont font;
    font.setPixelSize(label_font_size);
    label->setFont(font);
    label->setText("PRESS SPACE TO START GAME");
}

MainWindow::~MainWindow()
{
    delete ui;
    if(tubes != nullptr) {
        delete tubes;
    }
    if(bird != nullptr) {
        delete bird;
    }
    delete timer;
    delete timer_fall;
    delete image;
    delete rect;
    delete lcd;
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
           // qDebug() << score;
            lcd->display(score);
            i->pass();
        }
        if(bird->getRect()->intersects(*i->getTopTube())) {
            timer->stop();
            IsFalling = true;
            bird->Dump();
            timer_fall->start(speed);
        }
        if(bird->getRect()->intersects(*i->getDownTube())) {
            timer->stop();
            IsFalling = true;
            bird->Dump();
            timer_fall->start(speed);
        }
        if(i->getLeft() - bird->getLeft() < bird->getWidth() &&  bird->getLeft() < i->getRight() && bird->getTop() < 0) {
            timer->stop();
            IsFalling = true;
            bird->Dump();
            timer_fall->start(speed);
        }
        if(bird->getBottom() >= window_heigth) {
            timer->stop();
            IsFalling = true;
            bird->Dump();
        }
    }
}

void MainWindow::slotTimerFall() {
    repaint();
    if(bird->getBottom() >= window_heigth) {
        IsFalling = 0;
        timer_fall->stop();
    }
}


void MainWindow::keyPressEvent(QKeyEvent *event) {
  /*  if(!IsFalling) {
        if(event->key() == Qt::Key_Space) {
            bird->jump();
        }
    } */
    if(event->key() == Qt::Key_Space) {
        if(!IsFalling) {
            bird->jump();
        }
        if(IsNewWindow) {
            IsNewWindow = 0;
            startNewGame();
        }
        return;
    }
    if(event->key() == Qt::Key_R) {
        if(!IsFalling) {
            timer->stop();
        } else {
            timer_fall->stop();
        }
        finishGame();
        remakeScene();
        return;
    }
}

void MainWindow::remakeScene() {
    tubes = new Tubes(window_width, window_heigth);
    bird = new Bird();
    score = 0;
    lcd->display(score);
    IsFalling = 0;
    IsNewWindow = 1;
    IsGame = 0;
    repaint();
    label->setText("PRESS SPACE TO START GAME");
    label->show();
}

void MainWindow::startNewGame() {
    label->hide();
    IsGame = true;
    IsNewWindow = 0;
    timer->start(speed);
}

void MainWindow::finishGame() {
    IsGame = false;
    if(tubes != nullptr) {
        delete tubes;
    }
    if(bird != nullptr) {
        delete bird;
    }
}





