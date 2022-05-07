#ifndef BIRD_H
#define BIRD_H

#include <QPainter>

class Bird
{
public:
    Bird();
    ~Bird();
    const int x = 200;
    const int y = 200;
    QRect* rect;
    const int width = 35;
    const int heigth = 25;
    const int max_speed = 10;
    const int gravity = 1;
    int speed = 0;
    QImage* image;
    void update();
public:
    void jump();
    void paint_(QPainter* painter);
    void paint_fall_(QPainter* painter);
    int getTop();
    int getBottom();
    int getLeft();
    int getRight();
    int getWidth();
    QRect* getRect();
};

#endif // BIRD_H
