#include "ball.h"
double distance(QPoint a, QPoint b){
    return (a.x()-b.x()) * (a.x()-b.x()) + (a.y()-b.y()) * (a.y()-b.y());
}
int ball::getX() const
{
    return x;
}

int ball::getY() const
{
    return y;
}

int ball::getR() const
{
    return r;
}

ball::ball(int w, int h)
{
    r = 15 + rand()%15;
    x = 15 + rand()%(w-2*r);
    y = 15 + rand()%(h-2*r);

    color = QColor::fromRgb(rand()%256, rand()%256, rand()%256);

    vx = 1;
    vy = 1;
    if (rand()%2 == 0) vx *= -1;
    if (rand()%2 == 0) vy *= -1;
}
void ball::move(int w, int h){
    if (x+r+5>=w || x-r<=0){
        vx *= -1;
    }
    if (y+r+5>=h || y-r<=0){
        vy *= -1;
    }
    x += vx;
    y += vy;
}
void ball::draw(QPainter&painter){
    painter.setBrush(QBrush(color));
    painter.drawEllipse(x, y, r, r);
}

bool ball::intersects(ball *enemy)
{

    if (distance(QPoint(x, y), QPoint(enemy->x, enemy->y)) < (enemy->r*enemy->r)) {
        return true;
    }
    else{
        return false;
    }
}

void ball::revers()
{
    vx *= -1;
    vy *= -1;
}





