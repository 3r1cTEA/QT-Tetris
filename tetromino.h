#ifndef TETROMINO_H
#define TETROMINO_H

#include <QGraphicsRectItem>

class tetromino: public QGraphicsRectItem{
public:
    void keyPressEvent(QKeyEvent * event);
};

#endif // TETROMINO_H
