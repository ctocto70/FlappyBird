#include "tubes.h"
#include <QPixmap>
#include <QBrush>



Tube::Tube(const int& x, const int& y, const int& screen_width_, const int& screen_heigth_, const int& width_, const int& heigth_) {
    top_rect = new QRect(screen_width_, y - heigth_ / 2 - screen_heigth_, width_, screen_heigth_);
    down_rect = new QRect(screen_width_, y + heigth_ / 2, width_, screen_heigth_);
    IsPass = false;
}

int Tube::getRight() {
    return top_rect->right();
}

int Tube::getLeft() {
    return top_rect->left();
}

bool Tube::IsPassed() {
    return IsPass;
}

void Tube::pass() {
    IsPass = true;
}

Tube::~Tube() {
    delete top_rect;
    delete down_rect;
}

QRect* Tube::getTopTube() {
    return top_rect;
}

QRect* Tube::getDownTube() {
    return down_rect;
}













Tubes::Tubes(const int& screen_width_, const int& screen_heigth_): screen_width(screen_width_),
    screen_heigth(screen_heigth_)  {
    image1 = new QImage("C:\\QtProjects\\FlappyBird\\Tube_up.png", "PNG");
    image2 = new QImage("C:\\QtProjects\\FlappyBird\\Tube_down.png", "PNG");
    srand(time(0));
};
void Tubes::update() {
     for(int i = 0; i < tubes.size(); i++) {
             tubes[i]->getTopTube()->translate(-step, 0);
             tubes[i]->getDownTube()->translate(-step, 0);
         }
         int y = rand() % (screen_heigth - 2 * heigth) + heigth;
         if(tubes.isEmpty()) {
             Tube* tube = new Tube(screen_width, y, screen_width, screen_heigth, width, heigth);
             tubes.push_back(tube);
         }
         if(tubes.at(tubes.size() - 1)->getLeft() <= (screen_width - distance - width)) {
             Tube* tube = new Tube(screen_width, y, screen_width, screen_heigth, width, heigth);
             tubes.push_back(tube);
         }
         if(tubes.at(0)->getLeft() <= -width) {
             tubes.removeFirst();
         }
}

void Tubes::paint_(QPainter* painter) {
     update();
     for(auto i : tubes) {
         painter->drawImage(*i->getTopTube(), *image1);
         painter->drawImage(*i->getDownTube(), *image2);
     }
}

void Tubes::paint_fall_(QPainter* painter) {
    for(auto i : tubes) {
        painter->drawImage(*i->getTopTube(), *image1);
        painter->drawImage(*i->getDownTube(), *image2);
    }
}

QVector<Tube*> Tubes::getTubes() {
    return tubes;
}

Tubes::~Tubes() {
    delete image1;
    delete image2;
}


