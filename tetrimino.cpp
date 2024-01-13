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




    drawBlocks();


    this->setFlag(QGraphicsItem::ItemIsFocusable);
    this->setFocus();

        QTimer * timer = new QTimer();
        connect(timer,SIGNAL(timeout()),this,SLOT(moveDown()));

        timer->start(1000);
}

void tetrimino::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left){

            setX(x()-18);

            if(collisionSide())
            this->setX(x()+18);


        }
    else if (event->key() == Qt::Key_Right){

            setX(x()+18);
            if(collisionSide()){
                this->setX(x()-18);
            }

        }
    else if (event->key() == Qt::Key_Up ){
            setRotation(rotation()+90);
            if(collisionSide())
            {
               this->setRotation(rotation()-90);
            }

        }
    else if (event->key() == Qt::Key_Down){
        if(sceneBoundingRect().bottom()<190)
        {
            setPos(x(),y()+18);
            if(collisionSide())
            {
                setY(y()-18);
            }
        }
        }

}

void tetrimino::drawBlocks()
{

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
    this->setPos(0,-10*pix_l);

   //scene()->addItem(this);

}

void tetrimino::moveDown()
{
    if(this->sceneBoundingRect().bottom()<190)
    {
    //qDebug()<<sceneBoundingRect().bottom();
    setPos(x(),y()+18);
    if(collisionSide())
    {
        setY(y()-18);
        setToBoard();
        return;
    }
    }

    else
    {
        setToBoard();
        return;

    }

}

void tetrimino::setToBoard()
{
    this->clearFocus();
    isActive = false;
    this->gameboard->setFlag(QGraphicsItem::ItemIsFocusable);

    for(int i = 0; i<4; i++)
    {

        gameboard->addToGroup(this->childItems().first());





    }

    //scene()->addItem(gameboard);
    this->isActive=false;

    int rand_colour = rand() % 7 +1;

    tetrimino *teto = new tetrimino(18,rand_colour,gameboard);
    scene()->addItem(teto);

    delete this;

}

void tetrimino::collisionDown()
{
    for(int i = 0; i<gameboard->childItems().length(); i++)
    {
       if(gameboard->childItems().isEmpty())
       {

       }
       else
       {
           for(int j = 0; j <4; j++)
           {
              if(this->childItems()[j]->collidesWithItem(gameboard->childItems()[i]))
              {
                this->setY(y()-pix_l);
                this->setToBoard();
                return;
           }
           }
       }

    }
}

bool tetrimino::collisionSide()
{
    bool temp = false;
    if(!(sceneBoundingRect().left()>-160) || !(sceneBoundingRect().right()<120))
    {
        temp = true;
    }
    for(int i = 0; i<gameboard->childItems().length(); i++)
    {
       if(gameboard->childItems().isEmpty())
       {
        return temp;
       }
       else
       {
           for(int j = 0; j <4; j++)
           {
              if(this->childItems()[j]->collidesWithItem(gameboard->childItems()[i]))
              {

                temp = true;
                return temp;
           }
           }
       }

    }
    return temp;
}




