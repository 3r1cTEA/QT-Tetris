#ifndef BOARD_H
#define BOARD_H

#include <QGraphicsItemGroup>
#include <QGraphicsPixmapItem>

#include <QGraphicsTextItem>
#include <QFont>



class board: public QGraphicsItemGroup
{
public:
    board(int pix_l);
    int pix_l;
    bool gameOver();
    QGraphicsTextItem *scoretext;
    int score;


    //

    void checkLines();
    void checkLines(QGraphicsLineItem *checkLine);
    void scoreUpdate();
    void checkLoop();
    void drawScore();
    void drawLoss();


private:
    QGraphicsLineItem *checkLine;

    int increment;
    int min;
    int max;



};

#endif // BOARD_H
