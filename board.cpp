#include "board.h"
#include <QGraphicsScene>
#include <QRect>
#include <QGraphicsPixmapItem>
#include <QLine>
#include <QList>
#include <QDebug>


board::board()
{
 //checkLines();
}

void board::checkLines()
{
    QGraphicsLineItem *checkLine = new QGraphicsLineItem();

    checkLine->setLine(-160,18*9,150,18*9);

    checkLine->setVisible(false);

    scene()->addItem(checkLine);

    QList<QGraphicsItem *> colliding_items;
    QList<QGraphicsItem *> items_above;



    if (checkLine->collidingItems().count()==12)
    {
        for (int i = 0; i < this->childItems().count(); i++)
        {

           if(this->childItems()[i]->collidesWithItem(checkLine))
           {
               colliding_items.append(this->childItems()[i]);
           }
           else if((!this->childItems()[i]->collidesWithItem(checkLine)) && (this->childItems()[i]->y()>checkLine->y()))
            {
               items_above.append(this->childItems()[i]);
            }
        }


       for (int i = 0; i<colliding_items.length();i++)
       {delete colliding_items[i];}
       for (int i = 0; i<items_above.length();i++)
       {
           items_above[i]->setY(items_above[i]->y()+18);
       }


    }

}


