#include "validation.h"

validation::validation()
{
    //Nothing here
}

int validation::chooser(Tile *temp)
{
    switch(temp->pieceName)
    {

    case 'R': flag=validateJa(temp);
              break;

    case 'H': flag=validateJang(temp);
              break;

    case 'K': flag=validateWang(temp);
              break;

    case 'Q': flag=validateHoo(temp);
              break;

    case 'B': flag=validateSang(temp);
              break;

    }

    orange();

    return flag;
}



//Ja
int validation::validateJa(Tile *temp)
{
    int row, col;

    row = temp->row;
    col = temp->col;
    retVal = 0;

    //White Ja
    if (temp->pieceColor)
    {
        //Make sure team piece is not infront
        if (row-1 >=0 && !(tile[row-1][col]->piece && tile[row-1][col]->pieceColor))
        {
            exp[max++]=tile[row-1][col]->tileNum;
            retVal=1;
        }
    }
    //BlackJa
    else
    {
        if (row+1 <= 3 && !(tile[row+1][col]->piece && !tile[row+1][col]->pieceColor))
        {
            exp[max++]=tile[row+1][col]->tileNum;
            retVal=1;
        }
    }


    return retVal;
}


//Jang
int validation::validateJang(Tile *temp)
{
    int row, col;
    retVal = 0;

    row = temp->row;
    col = temp->col;

    //White Jang
    if (temp->pieceColor)
    {

        if (row-1 >= 0 && !(tile[row-1][col]->piece && tile[row-1][col]->pieceColor))
        {
            exp[max++]=tile[row-1][col]->tileNum;
            retVal=1;
        }

        if (row+1 <= 3 && !(tile[row+1][col]->piece && tile[row+1][col]->pieceColor))
        {
            exp[max++]=tile[row+1][col]->tileNum;
            retVal=1;
        }

        if (col+1 <= 2 && !(tile[row][col+1]->piece && tile[row][col+1]->pieceColor))
        {
            exp[max++]=tile[row][col+1]->tileNum;
            retVal=1;
        }

        if (col-1 >= 0 && !(tile[row][col-1]->piece && tile[row][col-1]->pieceColor))
        {
            exp[max++]=tile[row][col-1]->tileNum;
            retVal=1;
        }
    }
    //Black Jang
    else
    {

        if (row-1 >= 0 && !(tile[row-1][col]->piece && !tile[row-1][col]->pieceColor))
        {
            exp[max++]=tile[row-1][col]->tileNum;
            retVal=1;
        }

        if (row+1 <= 3 && !(tile[row+1][col]->piece && !tile[row+1][col]->pieceColor))
        {
            exp[max++]=tile[row+1][col]->tileNum;
            retVal=1;
        }

        if (col+1 <= 2 && !(tile[row][col+1]->piece && !tile[row][col+1]->pieceColor))
        {
            exp[max++]=tile[row][col+1]->tileNum;
            retVal=1;
        }

        if (col-1 >= 0 && !(tile[row][col-1]->piece && !tile[row][col-1]->pieceColor))
        {
            exp[max++]=tile[row][col-1]->tileNum;
            retVal=1;
        }
    }

    return retVal;
}


//Wang
int validation::validateWang(Tile *temp)
{
    int row,col;
    retVal=0;

    row=temp->row;
    col=temp->col;

    //White Wang
    if (temp->pieceColor)
    {
        if (row-1 >= 0 && !(tile[row-1][col]->piece && tile[row-1][col]->pieceColor))
        {
            exp[max++]=tile[row-1][col]->tileNum;
            retVal=1;
        }
        if (row+1 <= 3 && !(tile[row+1][col]->piece && tile[row+1][col]->pieceColor))
        {
            exp[max++]=tile[row+1][col]->tileNum;
            retVal=1;
        }

        if (col+1 <= 2 && !(tile[row][col+1]->piece && tile[row][col+1]->pieceColor))
        {
            exp[max++]=tile[row][col+1]->tileNum;
            retVal=1;
        }

        if (col-1 >= 0 && !(tile[row][col-1]->piece && tile[row][col-1]->pieceColor))
        {
            exp[max++]=tile[row][col-1]->tileNum;
            retVal=1;
        }

        if (col-1 >= 0 && row-1 >= 0 && !(tile[row-1][col-1]->piece && tile[row-1][col-1]->pieceColor))
        {
            exp[max++]=tile[row-1][col-1]->tileNum;
            retVal=1;
        }

        if (col-1 >= 0 && row+1 <= 3 && !(tile[row+1][col-1]->piece && tile[row+1][col-1]->pieceColor))
        {
            exp[max++]=tile[row+1][col-1]->tileNum;
            retVal=1;
        }

        if (col+1 <= 2 && row-1 >= 0 && !(tile[row-1][col+1]->piece && tile[row-1][col+1]->pieceColor))
        {
            exp[max++]=tile[row-1][col+1]->tileNum;
            retVal=1;
        }

        if (col+1 <= 2 && row+1 <= 3 && !(tile[row+1][col+1]->piece && tile[row+1][col+1]->pieceColor))
        {
            exp[max++]=tile[row+1][col+1]->tileNum;
            retVal=1;
        }
    }
    //Black Wang
    else
    {
        if (row-1 >= 0 && !(tile[row-1][col]->piece && !tile[row-1][col]->pieceColor))
        {
            exp[max++]=tile[row-1][col]->tileNum;
            retVal=1;
        }
        if (row+1 <= 3 && !(tile[row+1][col]->piece && !tile[row+1][col]->pieceColor))
        {
            exp[max++]=tile[row+1][col]->tileNum;
            retVal=1;
        }

        if (col+1 <= 2 && !(tile[row][col+1]->piece && !tile[row][col+1]->pieceColor))
        {
            exp[max++]=tile[row][col+1]->tileNum;
            retVal=1;
        }

        if (col-1 >= 0 && !(tile[row][col-1]->piece && !tile[row][col-1]->pieceColor))
        {
            exp[max++]=tile[row][col-1]->tileNum;
            retVal=1;
        }

        if (col-1 >= 0 && row-1 >= 0 && !(tile[row-1][col-1]->piece && !tile[row-1][col-1]->pieceColor))
        {
            exp[max++]=tile[row-1][col-1]->tileNum;
            retVal=1;
        }

        if (col-1 >= 0 && row+1 <= 3 && !(tile[row+1][col-1]->piece && !tile[row+1][col-1]->pieceColor))
        {
            exp[max++]=tile[row+1][col-1]->tileNum;
            retVal=1;
        }

        if (col+1 <= 2 && row-1 >= 0 && !(tile[row-1][col+1]->piece && !tile[row-1][col+1]->pieceColor))
        {
            exp[max++]=tile[row-1][col+1]->tileNum;
            retVal=1;
        }

        if (col+1 <= 2 && row+1 <= 3 && !(tile[row+1][col+1]->piece && !tile[row+1][col+1]->pieceColor))
        {
            exp[max++]=tile[row+1][col+1]->tileNum;
            retVal=1;
        }
    }
    return retVal;
}


//QUEEN
int validation::validateHoo(Tile *temp)
{
    int r,c;

    retVal=0;

    r=temp->row;
    c=temp->col;
    while(r-->0)
    {
        if(!tile[r][c]->piece)
        {
            exp[max++]=tile[r][c]->tileNum;
            retVal=1;
        }

        else if(tile[r][c]->pieceColor==temp->pieceColor)
            break;

        else if(tile[r][c]->pieceColor!=temp->pieceColor)
        {
            exp[max++]=tile[r][c]->tileNum;
            retVal=1;
            break;
        }
    }

    r=temp->row;
    c=temp->col;
    while(r++<7)
    {
        if(!tile[r][c]->piece)
        {
            exp[max++]=tile[r][c]->tileNum;
            retVal=1;
        }

        else if(tile[r][c]->pieceColor==temp->pieceColor)
            break;

        else if(tile[r][c]->pieceColor!=temp->pieceColor)
        {
            exp[max++]=tile[r][c]->tileNum;
            retVal=1;
            break;
        }
    }

    r=temp->row;
    c=temp->col;
    while(c++<7)
    {
        if(!tile[r][c]->piece)
        {
            exp[max++]=tile[r][c]->tileNum;
            retVal=1;
        }

        else if(tile[r][c]->pieceColor==temp->pieceColor)
            break;

        else if(tile[r][c]->pieceColor!=temp->pieceColor)
        {
            exp[max++]=tile[r][c]->tileNum;
            retVal=1;
            break;
        }
    }

    r=temp->row;
    c=temp->col;
    while(c-->0)
    {
        if(!tile[r][c]->piece)
        {
            exp[max++]=tile[r][c]->tileNum;
            retVal=1;
        }

        else if(tile[r][c]->pieceColor==temp->pieceColor)
            break;

        else if(tile[r][c]->pieceColor!=temp->pieceColor)
        {
            exp[max++]=tile[r][c]->tileNum;
            retVal=1;
            break;
        }
    }

    r=temp->row;
    c=temp->col;
    while(r-->0 && c++<7)
    {
        if(!tile[r][c]->piece)
        {
            exp[max++]=tile[r][c]->tileNum;
            retVal=1;
        }

        else if(tile[r][c]->pieceColor==temp->pieceColor)
            break;

        else if(tile[r][c]->pieceColor!=temp->pieceColor)
        {
            exp[max++]=tile[r][c]->tileNum;
            retVal=1;
            break;
        }
    }

    r=temp->row;
    c=temp->col;
    while(r-->0 && c-->0)
    {
        if(!tile[r][c]->piece)
        {
            exp[max++]=tile[r][c]->tileNum;
            retVal=1;
        }

        else if(tile[r][c]->pieceColor==temp->pieceColor)
            break;

        else if(tile[r][c]->pieceColor!=temp->pieceColor)
        {
            exp[max++]=tile[r][c]->tileNum;
            retVal=1;
            break;
        }
    }

    r=temp->row;
    c=temp->col;
    while(r++<7 && c++<7)
    {
        if(!tile[r][c]->piece)
        {
            exp[max++]=tile[r][c]->tileNum;
            retVal=1;
        }

        else if(tile[r][c]->pieceColor==temp->pieceColor)
            break;

        else if(tile[r][c]->pieceColor!=temp->pieceColor)
        {
            exp[max++]=tile[r][c]->tileNum;
            retVal=1;
            break;
        }
    }

    r=temp->row;
    c=temp->col;
    while(r++<7 && c-->0)
    {
        if(!tile[r][c]->piece)
        {
            exp[max++]=tile[r][c]->tileNum;
            retVal=1;
        }

        else if(tile[r][c]->pieceColor==temp->pieceColor)
            break;

        else if(tile[r][c]->pieceColor!=temp->pieceColor)
        {
            exp[max++]=tile[r][c]->tileNum;
            retVal=1;
            break;
        }
    }


    return retVal;
}

//Sang
int validation::validateSang(Tile *temp)
{
    int row,col;
    retVal=0;

    row=temp->row;
    col=temp->col;

    //White Sang
    if (temp->pieceColor)
    {
        if (col-1 >= 0 && row-1 >= 0 && !(tile[row-1][col-1]->piece && tile[row-1][col-1]->pieceColor))
        {
            exp[max++]=tile[row-1][col-1]->tileNum;
            retVal=1;
        }

        if (col-1 >= 0 && row+1 <= 3 && !(tile[row+1][col-1]->piece && tile[row+1][col-1]->pieceColor))
        {
            exp[max++]=tile[row+1][col-1]->tileNum;
            retVal=1;
        }

        if (col+1 <= 2 && row-1 >= 0 && !(tile[row-1][col+1]->piece && tile[row-1][col+1]->pieceColor))
        {
            exp[max++]=tile[row-1][col+1]->tileNum;
            retVal=1;
        }

        if (col+1 <= 2 && row+1 <= 3 && !(tile[row+1][col+1]->piece && tile[row+1][col+1]->pieceColor))
        {
            exp[max++]=tile[row+1][col+1]->tileNum;
            retVal=1;
        }
    }
    //Black Sang
    else
    {
        if (col-1 >= 0 && row-1 >= 0 && !(tile[row-1][col-1]->piece && !tile[row-1][col-1]->pieceColor))
        {
            exp[max++]=tile[row-1][col-1]->tileNum;
            retVal=1;
        }

        if (col-1 >= 0 && row+1 <= 3 && !(tile[row+1][col-1]->piece && !tile[row+1][col-1]->pieceColor))
        {
            exp[max++]=tile[row+1][col-1]->tileNum;
            retVal=1;
        }

        if (col+1 <= 2 && row-1 >= 0 && !(tile[row-1][col+1]->piece && !tile[row-1][col+1]->pieceColor))
        {
            exp[max++]=tile[row-1][col+1]->tileNum;
            retVal=1;
        }

        if (col+1 <= 2 && row+1 <= 3 && !(tile[row+1][col+1]->piece && !tile[row+1][col+1]->pieceColor))
        {
            exp[max++]=tile[row+1][col+1]->tileNum;
            retVal=1;
        }
    }
    return retVal;
}

int validation::check(Tile *temp)
{
    //int r,c,flag;
    retVal=0;

    return retVal;
}

void validation::orange()
{
    for(int i=0;i<max;i++)
        tile[exp[i]/3][exp[i]%3]->setStyleSheet("QLabel {background: orange; border:1px solid red}");
}


