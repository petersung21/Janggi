#include "tile.h"

#include "validation.h"

validation *valid = new validation();

extern int count,turn;
extern QWidget *myWidget;
extern Tile *click1;
extern Tile *tile[4][3];

void validate(Tile *temp,int c);
void disOrange();

void Tile::mousePressEvent(QMouseEvent *event)
{
    validate(this,++count);
}

void Tile::display(char elem)
{
    this->pieceName=elem;

    if(this->pieceColor && this->piece)
    {
        switch(elem)
        {
            case 'R': this->setPixmap(QPixmap(":/Images/rook_white.svg"));
                      break;
            case 'H': this->setPixmap(QPixmap(":/Images/knight_white.svg"));
                      break;
            case 'K': this->setPixmap(QPixmap(":/Images/king_white.svg"));
                      break;
            case 'B': this->setPixmap(QPixmap(":/Images/bishop_white.svg"));
                      break;  
            case 'Q': this->setPixmap(QPixmap(":/Images/queen_white.svg"));
                    break;
        }
    }

    else if(this->piece)
    {
        switch(elem)
        {
        case 'R': this->setPixmap(QPixmap(":/Images/rook_black.svg"));
                  break;
        case 'H': this->setPixmap(QPixmap(":/Images/knight_black.svg"));
                  break;
        case 'K': this->setPixmap(QPixmap(":/Images/king_black.svg"));
                  break;
        case 'B': this->setPixmap(QPixmap(":/Images/bishop_black.svg"));
                  break;
        case 'Q': this->setPixmap(QPixmap(":/Images/queen_black.svg"));
                  break;
        }
    }
    else
        this->clear();
}

void validate(Tile *temp, int c)
{
    int retValue,i;

    if(c==1)
    {
        if(temp->piece && (temp->pieceColor==turn))
        {
            //exp[max++]=temp->tileNum;
            retValue=valid->chooser(temp);

            if(retValue)
            {
                click1= new Tile();
                temp->setStyleSheet("QLabel {background: green;}");
                click1=temp;
            }
            else
            {
                //temp->setStyleSheet("QLabel {background: red;}");
                count=0;
            }
        }
        else
        {
            //qDebug()<<"Rascel, clicking anywhere";
            count=0;
        }
    }

    else
    {

        if(temp->tileNum==click1->tileNum)
        {
            click1->tileDisplay();
            disOrange();
            max=0;
            count=0;
        }

        for(i=0;i<max;i++)
        {
            if(temp->tileNum==exp[i])
            {
                click1->piece=0;
                temp->piece=1;

                temp->pieceColor=click1->pieceColor;
                temp->pieceName=click1->pieceName;

                click1->display(click1->pieceName);
                temp->display(click1->pieceName);

                click1->tileDisplay();
                temp->tileDisplay();

                retValue=valid->check(click1);
                /*
                if(retValue)
                {
                    tile[wR][wC]->setStyleSheet("QLabel {background: red;}");
                }
                */

                disOrange();

                max=0;

                turn=(turn+1)%2;
                count=0;
            }

            else
                count=1;
        }
    }
}

void Tile::tileDisplay()
{

    if(this->tileColor)
        this->setStyleSheet("QLabel {background: rgb(120, 120, 90); border:1px solid red}:hover{background: rgb(170,85,127); border:1px solid red}");
    else
        this->setStyleSheet("QLabel {background: rgb(211, 211, 158); border:1px solid red}:hover{background: rgb(170,95,127); border:1px solid red}");
}

void disOrange()
{
    int i;

    for(i=0;i<max;i++)
        tile[exp[i]/3][exp[i]%3]->tileDisplay();

}


