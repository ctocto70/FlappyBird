#include "tubes.h"
#include <QPixmap>
#include <QBrush>

Tubes::Tubes(const int& screen_width_, const int& screen_heigth_): screen_width(screen_width_),
    screen_heigth(screen_heigth_)  {
    image1 = new QImage("C:\\QtProjects\\FlappyBird\\Tube_up.png", "PNG");
    image2 = new QImage("C:\\QtProjects\\FlappyBird\\Tube_down.png", "PNG");
    srand(time(0));
};
void Tubes::update() {
    for(int i = 0; i < tubes.size(); i++) {
        tubes[i].first -= step;
    }
    int y = rand() % (screen_heigth - 2 * heigth) + heigth;
    if(tubes.isEmpty()) {
        tubes.push_back(qMakePair(screen_width, y));
    }
    if(tubes.at(tubes.size() - 1).first <= (screen_width - distance - width)) {
        tubes.push_back(qMakePair(screen_width, y));
    }
    if(tubes.at(0).first <= -width) {
        tubes.removeFirst();
    }
}

void Tubes::paint_(QPainter* painter) {
    update();
    for(auto i : tubes) {
        QRect rect1(i.first, i.second - heigth / 2 - screen_heigth, width, screen_heigth);
        painter->drawImage(rect1, *image1);
        QRect rect2(i.first, i.second + heigth / 2,
                   width, screen_heigth);
        painter->drawImage(rect2, *image2);

    }
}

Tubes::~Tubes() {
    delete image1;
    delete image2;
}

