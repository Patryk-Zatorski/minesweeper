#include "MSBoardTextView.hpp"
#include "MinesweeperBoard.hpp"
#include <vector>
#include <iostream>

using namespace std;

MSBoardTextView::MSBoardTextView(MinesweeperBoard & gameboard):board{gameboard}
{
    this->width=board.getBoardWidth();
    this->height=board.getBoardHeight();
}
void MSBoardTextView::display() const
{
    for(unsigned int i=0;i<this->height;i++)
    {
        for(unsigned int a=0;a<this->width;a++)
        {
            cout<<"[";
            cout<<this->board.getFieldInfo(i,a);
            cout<<"]";
        }
        cout<<endl;
    }
}