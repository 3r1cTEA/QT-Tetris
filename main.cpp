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
#include "board.h"






const int window_width = 320;
const int window_height = 480;








int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    QGraphicsScene * scene = new QGraphicsScene();

    board *gameBoard = new board();


    tetrimino *tetgroup = new tetrimino(18, 4, gameBoard);






    scene->addLine(-160,0,160,0);
    scene->addLine(0,-240,0,240);

    scene->addItem(tetgroup);
    gameBoard->setY(0);
    scene->addItem(gameBoard);



    QGraphicsView * view = new QGraphicsView(scene);



    view->show();
    view->setFixedWidth(window_width);
    view->setFixedHeight(window_height);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    return a.exec();
}
