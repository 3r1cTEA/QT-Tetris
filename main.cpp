#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QPixmap>
#include <QKeyEvent>



#include <QDebug>
#include "tertimino.h"




const int M = 20;
const int N = 10;
const int pix_l = 18;
const int window_width = 320;
const int window_height = 480;

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

class Tetrimino: public QGraphicsItemGroup
{
public:
    void keyPressEvent(QKeyEvent *event)
    {
        if (event->key() == Qt::Key_Left){
            if(x()>-144){
                setPos(x()-18,y());
                qDebug()<<x();
            }
            }
        else if (event->key() == Qt::Key_Right){
            if(x()<120){
                setPos(x()+18,y());
            }
            }
        else if (event->key() == Qt::Key_Up){
                setRotation(rotation()+90);
            }
        else if (event->key() == Qt::Key_Down){
                setPos(x(),y()+18);
            }
    }

};

void buildBlocks(int figures[7][4], Point quad[4], Tetrimino *tetgroup, int colour)
{
    //clip tetris tile
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

        tetgroup->addToGroup(tet);

        if(i==1)
           {
               tetgroup->setTransformOriginPoint(quad[i].x*pix_l,quad[i].y*pix_l);
           }

    }
}

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
int n = 2;
for (int i = 0; i <4; i++)
{
    quad[i].x= figures[n][i] % 2;
    quad[i].y= figures[n][i] / 2;
}

Tetrimino *tetgroup = new Tetrimino();

buildBlocks(figures,quad,tetgroup,1);
tetgroup->setFlag(QGraphicsItem::ItemIsFocusable);
tetgroup->setFocus();

scene->addItem(tetgroup);
scene->addLine(-160,0,160,0);
scene->addLine(0,-240,0,240);


QGraphicsView * view = new QGraphicsView(scene);

view->show();
view->setFixedWidth(window_width);
view->setFixedHeight(window_height);
view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


return a.exec();
}
