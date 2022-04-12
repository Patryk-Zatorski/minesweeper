#pragma once

#include "MinesweeperBoard.hpp"
#include "MSBoardTextView.hpp"

class MSTextController
{
private:
MinesweeperBoard &board;
MSBoardTextView &view;
public:
MSTextController(MinesweeperBoard &gameboard, MSBoardTextView &gameview);
void play();
};