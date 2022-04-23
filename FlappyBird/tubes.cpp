#include "tubes.h"
#include <QPixmap>


Tubes::Tubes(const int& screen_width_, const int& screen_heigth_): screen_width(screen_width_),
    screen_heigth(screen_heigth_)  {
    srand(time(0));
};
void Tubes::update() {
    for(int i = 0; i < tubes.size(); i++) {
        tubes[i].first -= step;
    }
    int y = rand() % (screen_heigth - 2 * heigth) + heigth / 2;
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
    painter->setBrush(Qt::red);
    painter->setPen(Qt::red);
    for(auto i : tubes) {
        painter->drawRect(i.first, 0, width, i.second - heigth / 2);
        painter->drawRect(i.first, i.second + heigth / 2,
                          width, screen_heigth - i.second - heigth / 2);
    }
}

