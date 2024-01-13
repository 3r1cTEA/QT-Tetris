#ifndef BOARD_H
#define BOARD_H

#include <QGraphicsItemGroup>
#include <QGraphicsPixmapItem>


class board: public QGraphicsItemGroup
{
public:
    board();

    int field[20][10];

    void checkLines();

};

#endif // BOARD_H
