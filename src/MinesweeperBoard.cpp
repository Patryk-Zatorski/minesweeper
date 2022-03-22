#include "MinesweeperBoard.hpp"
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

MinesweeperBoard::MinesweeperBoard(int width, int height, GameMode mode)
{
    this->height=height;
    this->width=width;
    for(int i=0; i<height;i++)
    {
        this->board.push_back(vector<Field>());
        for(int a=0;a<width;a++)
        {
            this->board[i].push_back(Field{0,0,0});
        }
    }

    //generating debug map
    if(width>1&&height>1&&mode==GameMode::DEBUG)
    {
        for(int i=0; i<height;i++)
        {
            for(int a=0;a<width;a++)
            {
               if(i%2==0){this->board[i][a].hasMine=1;}
               if(a==0){this->board[i][a].hasMine=1;}
               if(i==a){this->board[i][a].hasMine=1;}
            }
        }
    }
    
    //calculating the number of mines to put on map
    int minesToGenerate=0;
    if(mode==GameMode::EASY){
        minesToGenerate=width*height*0.1;
    }
    if(mode==GameMode::NORMAL){
        minesToGenerate=width*height*0.2;
    }
    if(mode==GameMode::HARD){
        minesToGenerate=width*height*0.3;
    }
    mineCount=minesToGenerate;

    //generating mines in random spots
    srand(time(nullptr));
    while(minesToGenerate>0)
    {
        int i,a;
        a=rand()%width;
        i=rand()%height;
        if(this->board[i][a].hasMine!=1)
        {
            this->board[i][a].hasMine=1;
            minesToGenerate+=-1;
        }
    }
}

void MinesweeperBoard::debug_display() const
{
    for(int i=0;i<this->height;i++)
    {
        for(int a=0;a<this->width;a++)
        {
            cout<<"[";
            if(this->board[i][a].hasMine)
            {cout<<"M";}else{cout<<".";}
            if(this->board[i][a].hasFlag)
            {cout<<"O";}else{cout<<".";}
            if(this->board[i][a].isRevealed)
            {cout<<"F";}else{cout<<".";}
            cout<<"]";
        }
        cout<<endl;
    }
}

int MinesweeperBoard::getBoardWidth() const
{
    return this->width;
}

int MinesweeperBoard::getBoardHeight() const
{
    return this->height;
}

int MinesweeperBoard::getMineCount() const
{
    return this->mineCount;
}

int MinesweeperBoard::countMines(int row, int col) const
{
    if(row>this->height||col>this->width){return -1;}
    int amount=0;
    if(this->board[row-1][col-1].hasMine){amount++;}
    if(this->board[row-1][col].hasMine){amount++;}
    if(this->board[row-1][col+1].hasMine){amount++;}
    if(this->board[row][col+1].hasMine){amount++;}
    if(this->board[row+1][col+1].hasMine){amount++;}
    if(this->board[row+1][col].hasMine){amount++;}
    if(this->board[row+1][col-1].hasMine){amount++;}
    if(this->board[row][col-1].hasMine){amount++;}
    return amount;
}

bool MinesweeperBoard::hasFlag(int row, int col) const
{
    if(row>this->height||col>this->width){return 0;}
    if(this->board[row][col].hasFlag!=true){return 0;}
    if(this->board[row][col].isRevealed==true){return 0;}
    return 1;
}

void MinesweeperBoard::toggleFlag(int row, int col)
{
    if(!(row>this->height)&&!(col>this->width))
    {
        if(this->board[row][col].isRevealed==0)
        {
            if(this->stateOfTheGame==GameState::RUNNING)
            {
                this->board[row][col].hasFlag=1;
            }
        }
    }
}

void MinesweeperBoard::revealField(int row, int col)
{
    if(!(row>this->height)&&!(col>this->width))
    {
        if(this->board[row][col].isRevealed==0)
        {
            if(this->stateOfTheGame==GameState::RUNNING)
            {
                if(this->board[row][col].hasFlag==1)
                {
                    this->board[row][col].isRevealed=1;
                }
            }
        }
    }
}

bool MinesweeperBoard::isRevealed(int row, int col) const
{
    if(this->board[row][col].isRevealed==0){return 0;}else{return 1;}
}

GameState MinesweeperBoard::getGameState() const
{
    //check if the game is lost
    for(int i=0; i<height;i++)
    {
        for(int a=0;a<width;a++)
        {
            if(this->board[i][a].hasMine==1&&this->board[i][a].isRevealed==1){return GameState::FINISHED_LOSS;}
        }
    }

    //check if there are still tiles to be revealed
    for(int i=0; i<height;i++)
    {
        for(int a=0;a<width;a++)
        {
            if(this->board[i][a].hasMine==0&&this->board[i][a].isRevealed==0){return GameState::RUNNING;}
        }
    }
    return GameState::FINISHED_WIN;
}

char MinesweeperBoard::getFieldInfo(int row, int col) const
{
    if(row>this->height||col>this->width){return '#';}
    if(this->board[row][col].hasFlag==1&&this->board[row][col].isRevealed==0){return 'F';}
    if(this->board[row][col].hasFlag==0&&this->board[row][col].isRevealed==0){return '_';}
    if(this->board[row][col].hasMine==1&&this->board[row][col].isRevealed==1){return 'X';}
    if(this->board[row][col].isRevealed==1&&countMines(row,col)==0){return ' ';}
    if(this->board[row][col].isRevealed==1&&countMines(row,col)!=0){return countMines(row,col)+48;}
    return 'A';
}