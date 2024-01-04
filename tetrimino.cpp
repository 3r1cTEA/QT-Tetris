#include "tetrimino.h"
#include <QTimer>


tetrimino::tetrimino()
{
    // connect
        QTimer * timer = new QTimer();
        connect(timer,SIGNAL(timeout()),this,SLOT(moveDown()));

        timer->start(1000);
}

void tetrimino::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left){
        if(sceneBoundingRect().left()>-160){
            setPos(x()-18,y());
            //qDebug()<<sceneBoundingRect().left();
        }
        }
    else if (event->key() == Qt::Key_Right){
        if(sceneBoundingRect().right()<120){
            setPos(x()+18,y());
        }
        }
    else if (event->key() == Qt::Key_Up){
            setRotation(rotation()+90);
        }
    else if (event->key() == Qt::Key_Down ){
        if(sceneBoundingRect().bottom()<240)
        {
            setPos(x(),y()+18);
        }
        }

}

void tetrimino::moveDown()
{
    if(sceneBoundingRect().bottom()<240)
    {
    setPos(x(),y()+18);
    }
}


