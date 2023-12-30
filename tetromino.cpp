#include <QKeyEvent>
#include "tetromino.h"

void tetromino::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Left){
        setPos(x()-10,y());
    }
    else if (event->key() == Qt::Key_Right){
        setPos(x()+10,y());
    }
    else if (event->key() == Qt::Key_Up){
        setRotation(rotation()+90);
    }
    else if (event->key() == Qt::Key_Down){
        setPos(x(),y()+10);
    }
}
