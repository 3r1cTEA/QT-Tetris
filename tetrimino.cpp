#include "tetrimino.h"
#include <QTimer>
#include <QDebug>


tetrimino::tetrimino()
{

    pix_l = 18;
    colour = 2;


    drawBlocks();

    this->setFlag(QGraphicsItem::ItemIsFocusable);
    this->setFocus();
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

void tetrimino::drawBlocks()
{
    qDebug()<<figures;
    QRect recto(pix_l*colour, 0, pix_l, pix_l);
    QPixmap image(":/tiles.png");
    QPixmap copy ;
    copy = image.copy(recto);

    //set tetrimino shape
    int n = colour;
    for (int i = 0; i <4; i++)
    {
        quad[i].x= figures[n][i] % 2;
        quad[i].y= figures[n][i] / 2;
    }

    for (int i=0; i <4; i++)
    {
        QGraphicsPixmapItem * tet = new QGraphicsPixmapItem();
        tet->setPixmap(copy);
        tet->setPos(quad[i].x*pix_l,quad[i].y*pix_l);


        this->addToGroup(tet);


        if(i==1)
           {
               this->setTransformOriginPoint(quad[i].x*pix_l,quad[i].y*pix_l);
           }

    }

}

void tetrimino::moveDown()
{
    if(sceneBoundingRect().bottom()<240)
    {
    setPos(x(),y()+18);
    }
    else
    {
        //this->removeFromGroup(this->childItems().first());
        return;

    }

}




