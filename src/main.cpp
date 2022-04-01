#include "MinesweeperBoard.hpp"
#include "MSBoardTextView.hpp"
#include "MSTextController.hpp"
#include <iostream>

using namespace std;

int main()
{
    MinesweeperBoard M(9,9,GameMode::EASY);
    MSBoardTextView view(M);
    M.debug_display();
    M.countMines(2,2);
    MSTextController controller(M,view);
    controller.play();
}
