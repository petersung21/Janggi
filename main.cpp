#include "mainwindow.h"
#include <QApplication>
#include "tile.h"

int count=0,turn=1,exp[60],max=0, bPieces=4, wPieces=4;
int wR,wC,bR,bC;
Tile *click1;

Tile *tile[4][3] = { { NULL } };

class Border
{
public:
    Border();
    void outline(QWidget *baseWidget, int xPos, int yPos, int Pos)
    {
         QLabel *outLabel = new QLabel(baseWidget);

        if(!Pos)
            outLabel->setGeometry(xPos,yPos,412,20);        //Horizontal Borders

        else
            outLabel->setGeometry(xPos,yPos,20,512);        //Vertical Borders

        outLabel->setStyleSheet("QLabel { background :rgb(170, 170, 127); color : black; }");
    }
};

void accessories(QWidget *baseWidget)
{
    QLabel *player2 = new QLabel(baseWidget);
    QLabel *name2 = new QLabel("Player 2", baseWidget);
    QLabel *time2 = new QLabel("00:00:00", baseWidget);

    QLabel *player1 = new QLabel(baseWidget);
    QLabel *name1 = new QLabel("Player 1", baseWidget);
    QLabel *time1 = new QLabel("00:00:00", baseWidget);

    QLabel *moves = new QLabel(baseWidget);

    name1->setGeometry(120,610,60,20);
    name1->setStyleSheet("background:rgb(211, 211, 158);");
    time1->setGeometry(120,635,60,20);
    time1->setStyleSheet("background:rgb(211, 211, 158);");
    player1->setGeometry(100,500,100,100);
    player1->setPixmap(QPixmap(":/Images/profile.png"));

    name2->setGeometry(120,210,60,20);
    name2->setStyleSheet("background:rgb(211, 211, 158);");
    time2->setGeometry(120,235,60,20);
    time2->setStyleSheet("background:rgb(211, 211, 158);");
    player2->setGeometry(100,100,100,100);
    player2->setPixmap(QPixmap(":/Images/profile.png"));

    moves->setGeometry(900,100,400,550);
    moves->setStyleSheet("background: rgb(211, 211, 158);");
}

void chessBoard(QWidget *baseWidget, Tile *tile[4][3])
{
    int i,j,k=0, hor, ver;
    Border *border[4] = {NULL};

    //Border
    {
        border[0]->outline(baseWidget,330,105,0);
        border[1]->outline(baseWidget,330,620,0);
        border[2]->outline(baseWidget,330,125,1);
        border[3]->outline(baseWidget,722,125,1);
    }

    //Create 12 tiles
    ver = 125;
    for(i=0; i<4; i++)
    {
        hor = 350;
        for(j=0; j<3; j++)
        {
            tile[i][j] = new Tile(baseWidget);
            if (i==0 || i==3)
            {
                tile[i][j]->tileColor=1;
            }
            else
            {
                tile[i][j]->tileColor=0;
            }
            tile[i][j]->piece=0;
            tile[i][j]->row=i;
            tile[i][j]->col=j;
            tile[i][j]->tileNum=k++;
            tile[i][j]->tileDisplay();
            tile[i][j]->setGeometry(hor,ver,124, 124);
            hor+=124;
        }
        ver+=124;
    }

    //Sang
    tile[0][2]->piece=1;
    tile[0][2]->pieceColor=0;
    tile[0][2]->display('B');
    tile[3][0]->piece=1;
    tile[3][0]->pieceColor=1;
    tile[3][0]->display('B');

    //Wang
    tile[0][1]->piece=1;
    tile[0][1]->pieceColor=0;
    tile[0][1]->display('K');
    tile[3][1]->piece=1;
    tile[3][1]->pieceColor=1;
    tile[3][1]->display('K');

    //Jang
    tile[0][0]->piece=1;
    tile[0][0]->pieceColor=0;
    tile[0][0]->display('H');
    tile[3][2]->piece=1;
    tile[3][2]->pieceColor=1;
    tile[3][2]->display('H');

    //Ja
    tile[1][1]->piece=1;
    tile[1][1]->pieceColor=0;
    tile[1][1]->display('R');
    tile[2][1]->piece=1;
    tile[2][1]->pieceColor=1;
    tile[2][1]->display('R');
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget *myWidget = new QWidget();
    myWidget->setGeometry(0,0,1370,700);
    myWidget->setStyleSheet("background-image: url(:/Images/KoreanPaintingBackground.jpg)");
    //myWidget->setAutoFillBackground(true);

    accessories(myWidget);
    chessBoard(myWidget,tile);

    myWidget->show();
    return a.exec();
}


