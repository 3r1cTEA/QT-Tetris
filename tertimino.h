#ifndef TERTIMINO_H
#define TERTIMINO_H

#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
class Tertimino: public QGraphicsItemGroup
{
public:

    void keyPressEvent(QKeyEvent* event);

};

#endif // TERTIMINO_H
