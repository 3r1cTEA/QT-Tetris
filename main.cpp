#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QPixmap>




#include <QDebug>
#include "tertimino.h"
#include "MyRect.h"



const int M = 20;
const int N = 10;
const int pix_l = 18;

int field[M][N];

struct Point
{int x,y;} quad[4], quab[4];



int figures[7][4] =
{
    1,3,5,7, // I
    2,4,5,7, // Z
    3,5,4,6, // S
    3,5,4,7, // T
    2,3,5,7, // L
    3,5,7,6, // J
    2,3,4,5, // O
};

int main(int argc, char *argv[])
{

QApplication a(argc, argv);
QGraphicsScene * scene = new QGraphicsScene();

       //clip tetris tile
       QRect recto(pix_l*3, 0, pix_l, pix_l);
       QPixmap image(":/tiles.png");
       QPixmap copy ;
       copy = image.copy(recto);

       //set tetrimino shape
       int n = 0;
       for (int i = 0; i <4; i++)
       {
           quad[i].x= figures[n][i] % 2;
           quad[i].y= figures[n][i] / 2;
       }

       //int *dx = new int;
       for (int i=0; i <4; i++)
       {
       // create an item to add to the scene
       Tertimino * tet = new Tertimino();
       tet->setPixmap(copy);


       tet->setPos(quad[i].x*pix_l,quad[i].y*pix_l);
       if (i==0){
       tet->setFlag(QGraphicsItem::ItemIsFocusable);
       tet->setFocus();
        }



       scene->addItem(tet);

       }



       QGraphicsView * view = new QGraphicsView(scene);

       view->show();
       view->setFixedWidth(320);
       view->setFixedHeight(480);

       return a.exec();
}
