#include "tertimino.h"
#include <QKeyEvent>
#include <QPixmap>
#include <QDebug>





void Tertimino::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left){
            setPos(x()-18,y());


        }
        else if (event->key() == Qt::Key_Right){
            setPos(x()+18,y());
        }
        else if (event->key() == Qt::Key_Up){
            setRotation(rotation()+90);
            //setTransformOriginPoint(x(),y()-18);
            qDebug()<<y();
        }
        else if (event->key() == Qt::Key_Down){
            setPos(x(),y()+18);}

    }







