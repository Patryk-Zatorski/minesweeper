#include "MinesweeperBoard.hpp"
#include "MSBoardTextView.hpp"
#include <iostream>

using namespace std;

int main()
{
    MinesweeperBoard M(20,10,GameMode::EASY);
    M.debug_display();
    MSBoardTextView view(M);
    view.display();
    M.revealField(5,0);
    cout<<"#############################"<<endl;
    view.display();
}
