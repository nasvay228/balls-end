#include "player.h"
player::player()
{
    x = y = 0;
}

void player::draw(QPainter &painter)
{
    painter.drawPixmap(x, y, 60, 60, QPixmap(":/files/images/pudge.jpeg"));
}

void player::peoples_move(int x, int y)
{
    this->x += x;
    this->y += y;
}

bool player::intersects(ball *enemy)
{
    int x1 = x;
    int y1 = y;

    int x3 = enemy->getX();
    int y3 = enemy->getY();

    QRect playerHitbox(x1,y1, 60, 60);
    QRect ballHitbox(x3, y3, enemy->getR()*2, enemy->getR()*2);

    if (playerHitbox.intersects(ballHitbox)) {
        return true;
    }
    else{
        return false;
    }

}


