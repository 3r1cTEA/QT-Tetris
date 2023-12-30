#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QPixmap>



const int M = 20;
const int N = 10;

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

    QGraphicsScene *scene = new QGraphicsScene();

    //QGraphicsRectItem *rect = new QGraphicsRectItem();

    QRect rect(36, 0, 18, 18);
    QPixmap image(":/tiles.png");
    QPixmap copy ;
    copy = image.copy(rect);

    int n = 0;
    for (int i = 0; i <4; i++)
    {
        quad[i].x= figures[n][i] % 2;
        quad[i].y= figures[n][i] / 2;
    }


    QPixmap* pCircle = new QPixmap(copy);
   // QPixmap* pCircle = porig->copy(rect);
    for (int i=0; i <4; i++)
    {
        QGraphicsPixmapItem* pItem = new QGraphicsPixmapItem(*pCircle);
        pItem->setPos(quad[i].x*18,quad[i].y*18);
        scene->addItem(pItem);
    }

    //scene->addPixmap(copy);

    QGraphicsView *view = new QGraphicsView(scene);

    view->setFixedWidth(320);
    view->setFixedHeight(480);

    view->show();

    return a.exec();
}
