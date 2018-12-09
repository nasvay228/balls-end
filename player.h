#ifndef PLAYER_H
#define PLAYER_H
#include <QPainter>
#include "ball.h"
class player

{
public:
    int x;
    int y;
    player();


    void draw(QPainter& painter);
    void peoples_move(int x, int y);
    bool intersects(ball * enemy);
    void hp();
};

#endif // PLAYER_H
