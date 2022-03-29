#pragma once

#include "MinesweeperBoard.hpp"

class MSBoardTextView
{
    private:
        unsigned int width,height;
        MinesweeperBoard &board;
    public:
    MSBoardTextView(MinesweeperBoard & gameboard);
    void display() const;
};