#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QGraphicsScene>



#include "tetromino.h"

const int M = 20;
const int N = 10;

int field[M][N] = {0};

struct Point
{int x,y;} a[4], b[4];

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

    QGraphicsScene *scene = new QGraphicsScene();

    //QGraphicsRectItem *rect = new QGraphicsRectItem();

    tetromino *rect = new tetromino();
    QBrush red(Qt::red);
    QPen blackpen(Qt::black);
    blackpen.setWidth(2);

    rect->setRect(0,0,18,18);
    rect->setBrush(red);
    rect->setPen(blackpen);

    tetromino *recto = new tetromino();

    blackpen.setWidth(2);

    recto->setRect(18,0,18,18);
    recto->setBrush(red);
    recto->setPen(blackpen);




    scene->addItem(rect);
    scene->addItem(recto);

    rect->setFlag(QGraphicsItem::ItemIsFocusable);
    rect->setFocus();

    QGraphicsView *view = new QGraphicsView(scene);

    view->setFixedWidth(320);
    view->setFixedHeight(480);

    view->show();

    return a.exec();
}
