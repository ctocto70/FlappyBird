#include "bird.h"

Bird::Bird()
{
    image_bird = new QImage("C:\\QtProjects\\FlappyBird\\Bird.png", "PNG");
    QImage* img;
    img = new QImage("C:\\QtProjects\\FlappyBird\\Bird1.png", "PNG");
    flying_bird.push_back(img);
    img = new QImage("C:\\QtProjects\\FlappyBird\\Bird2.png", "PNG");
    flying_bird.push_back(img);
    img = new QImage("C:\\QtProjects\\FlappyBird\\Bird3.png", "PNG");
    flying_bird.push_back(img);
    img = new QImage("C:\\QtProjects\\FlappyBird\\Bird4.png", "PNG");
    flying_bird.push_back(img);
    rect = new QRect(x, y, width, heigth);
}
void Bird::jump() {
    speed = max_speed;
}

void Bird::update() {
    rect->translate(0, -speed);
    speed -= gravity;
    picture_number += 1;
    picture_number %= number_of_pictures;
}

void Bird::paint_(QPainter* painter) {
    update();
    painter->setBrush(Qt::green);
    painter->setBrush(Qt::green);
    painter->setPen(Qt::green);
    if(!IsDump)  {
        painter->drawImage(*rect, *flying_bird[picture_number]);
    } else {
        painter->drawImage(*rect, *image_bird);
    }
}

void Bird::paint_fall_(QPainter* painter) {
    paint_(painter);
}

Bird::~Bird() {
    delete image_bird;
    for(auto i : flying_bird) {
        delete i;
    }
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

void Bird::Dump() {
    IsDump = true;
}
