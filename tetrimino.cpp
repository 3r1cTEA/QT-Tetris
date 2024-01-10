#include "tetrimino.h"

#include <QTimer>
#include <QDebug>
#include <QList>


tetrimino::tetrimino()
{
    isActive = true;
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

tetrimino::tetrimino(int pix_l, int colour, board *gameboard): pix_l{pix_l}, colour{colour}, gameboard{gameboard}
{
    isActive = true;
    //pix_l = 18;
    //colour = 2;



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

    QRect recto(pix_l*colour, 0, pix_l, pix_l);
    QPixmap image(":/tiles.png");
    QPixmap copy ;
    copy = image.copy(recto);

    QList<QGraphicsPixmapItem*> * benchode = new QList<QGraphicsPixmapItem*>();


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

        benchode->append(tet);

        this->addToGroup(tet);


        if(i==1)
           {
               this->setTransformOriginPoint(quad[i].x*pix_l,quad[i].y*pix_l);
           }

    }

   // scene()->addItem(this);

}

void tetrimino::moveDown()
{
    if(this->sceneBoundingRect().bottom()<190)
    {
    //qDebug()<<sceneBoundingRect().bottom();
    setPos(x(),y()+18);
    }
    else
    {
        setToBoard();
       // return;

    }

}

void tetrimino::setToBoard()
{
    this->clearFocus();
    isActive = false;
    this->gameboard->setFlag(QGraphicsItem::ItemIsFocusable);
    //gameboard->setFocus();
    //qDebug()<<"is Active is"<<isActive;


    for(int i = 0; i<4; i++)
    {

        gameboard->addToGroup(this->childItems().first());
        //qDebug()<<gameboard->y();
        //gameboard->setY(200);
       // qDebug()<<gameboard->y();
        //gameboard->drawnew();



    }

    delete this;

}




