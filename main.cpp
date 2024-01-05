#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QPixmap>
#include <QKeyEvent>
#include <QTimer>
#include <QObject>


#include <QDebug>
#include "tetrimino.h"




const int M = 20;
const int N = 10;

const int window_width = 320;
const int window_height = 480;

int field[M][N];






int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    QGraphicsScene * scene = new QGraphicsScene();



    tetrimino *tetgroup = new tetrimino();



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
