#include "bird.h"

Bird::Bird()
{
    image = new QImage("C:\\QtProjects\\FlappyBird\\Bird.png", "PNG");
}
void Bird::jump() {
    speed = max_speed;
}

void Bird::update() {
    y -= speed;
    speed -= gravity;
}

void Bird::paint_(QPainter* painter) {
    update();
    painter->setBrush(Qt::green);
    painter->setPen(Qt::green);
    QRect rect(x, y, width, heigth);
    painter->drawImage(rect, *image);
}

Bird::~Bird() {
    delete image;
}
