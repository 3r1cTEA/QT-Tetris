#ifndef TETRIMINO_H
#define TETRIMINO_H

#include <QObject>
#include <QGraphicsItemGroup>
#include <QKeyEvent>

class tetrimino: public QObject, public QGraphicsItemGroup
{
   Q_OBJECT
public:
   tetrimino();
   void keyPressEvent(QKeyEvent * event);

public slots:
   void moveDown();
};

#endif // NEWTETROMINO_H
