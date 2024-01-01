#ifndef TERTIMINO_H
#define TERTIMINO_H

#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
class Tertimino: public QGraphicsPixmapItem
{
public:

    //int dx;
    void keyPressEvent(QKeyEvent* event);
    int pos_return();
    void draw_rest(int x, int y, QPixmap tile, QGraphicsScene *scene);
};

#endif // TERTIMINO_H
