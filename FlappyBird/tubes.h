#ifndef TUBE_H
#define TUBE_H

#include <QVector>
#include <QPair>
#include <ctime>
#include <QPainter>


class Tubes
{
    const int distance = 250;
    const int width = 75; // length of the tube
    const int heigth = 150; // length og the hole
    const int screen_width; // "length"
    const int screen_heigth;
    const int step = 5;
    QImage* image1;
    QImage* image2;
    QVector<QPair<int, int>> tubes;
public:
    Tubes(const int& screen_width_, const int& screen_heigth_);
    ~Tubes();
    void update();
public:
    void paint_(QPainter* painter);
};

#endif // TUBE_H
