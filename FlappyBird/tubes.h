#ifndef TUBE_H
#define TUBE_H
#include <QVector>
#include <QPair>
#include <ctime>
#include <QPainter>

class Tube {
public:
    Tube(const int& x, const int& y, const int& screen_width_, const int& screend_heigth_, const int& width_, const int& heigth_);
    ~Tube();
    int getRight();
    int getLeft();
    QRect* getTopTube();
    QRect* getDownTube();
    void pass();
    bool IsPassed();
private:
    QRect* top_rect;
    QRect* down_rect;
    bool IsPass;
};

class Tubes
{
    const int distance = 250;
    const int width = 75; // length of the tube
    const int heigth = 150; // length og the hole
    const int screen_width; // "length"
    const int screen_heigth;
    const int step = 7;
    QImage* image1;
    QImage* image2;
    QVector<Tube*> tubes;
public:
    Tubes(const int& screen_width_, const int& screen_heigth_);
    ~Tubes();
    void update();
    QVector<Tube*> getTubes();
public:
    void paint_(QPainter* painter);
    void paint_fall_(QPainter* painter);
};


#endif // TUBE_H
