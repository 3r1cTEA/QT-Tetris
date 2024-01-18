#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QPixmap>
#include <QKeyEvent>
#include <QTimer>
#include <QObject>
#include <QLine>


#include <QDebug>

#include "tetrimino.h"
#include "board.h"






const int window_width = 320;
const int window_height = 480;

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    QGraphicsScene * scene = new QGraphicsScene();



    QPixmap image(":/background.png");
    QGraphicsPixmapItem * back = new QGraphicsPixmapItem();
    back->setPixmap(image);
    back->setScale(1);
    back->setPos(-160, -220);
    scene->addItem(back);






    board *gameBoard = new board();

    tetrimino *tetgroup = new tetrimino(18, 6, gameBoard);





    scene->addItem(tetgroup);
    scene->addItem(gameBoard);



    QGraphicsView * view = new QGraphicsView(scene);



    view->show();
    view->setFixedWidth(window_width);
    view->setFixedHeight(window_height);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    return a.exec();
}
