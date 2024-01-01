#include "tertimino.h"
#include <QKeyEvent>
#include <QPixmap>
#include <QDebug>




void Tertimino::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left){
            setPos(x()-18,y());
            qDebug()<<this->x();

        }
        else if (event->key() == Qt::Key_Right){
            setPos(x()+18,y());
        }
        else if (event->key() == Qt::Key_Up){
            setPos(x(),y()-18);
        }
        else if (event->key() == Qt::Key_Down){
            setPos(x(),y()+18);
    }


}

int Tertimino::pos_return()
{
    return this->x();


}

void draw_rest(int x, int y, QPixmap tile, QGraphicsScene *scene)
{
    QGraphicsPixmapItem *newtile = new QGraphicsPixmapItem();
    newtile->setPixmap(tile);
    newtile->setPos(x+10,y);
    //scene()->addItem(newtile);
}
