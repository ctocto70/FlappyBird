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

    QPalette pal = QPalette();
    pal.setColor(QPalette::Window, QColor(117,187,253));
    this->setAutoFillBackground(true);
    this->setPalette(pal);

    tubes = new Tubes(window_width, window_heigth);
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(slotTimerAlarm()));
    timer->start(speed); // И запустим таймер
}

MainWindow::~MainWindow()
{
    delete ui;
    delete tubes;
    delete timer;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter* painter = new QPainter(this);
    tubes->paint_(painter);
    delete painter;
}

void MainWindow::slotTimerAlarm() {
    repaint();
}

