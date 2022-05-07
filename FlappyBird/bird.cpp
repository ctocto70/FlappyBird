#include "bird.h"

Bird::Bird()
{
    image = new QImage("C:\\QtProjects\\FlappyBird\\Bird.png", "PNG");
    rect = new QRect(x, y, width, heigth);
}
void Bird::jump() {
    speed = max_speed;
}

void Bird::update() {
    rect->translate(0, -speed);
    speed -= gravity;
}

void Bird::paint_(QPainter* painter) {
    update();
    painter->setBrush(Qt::green);
    painter->setBrush(Qt::green);
    painter->setPen(Qt::green);
    painter->drawImage(*rect, *image);
}

void Bird::paint_fall_(QPainter* painter) {
    paint_(painter);
}

Bird::~Bird() {
    delete image;
    delete rect;
}

QRect* Bird::getRect() {
    return rect;
}

int Bird::getBottom() {
    return rect->bottom();
}

int Bird::getLeft() {
    return rect->left();
}

int Bird::getRight() {
    return rect->right();
}

int Bird::getWidth() {
    return width;
}

int Bird::getTop() {
    return rect->top();
}
