#include "MinesweeperBoard.hpp"

MinesweeperBoard::MinesweeperBoard(int width, int height, GameMode mode)
{
}

void MinesweeperBoard::debug_display() const
{
}

int MinesweeperBoard::getBoardWidth() const
{
}

int MinesweeperBoard::getBoardHeight() const
{
}

int MinesweeperBoard::getMineCount() const
{
}

int MinesweeperBoard::countMines(int row, int col) const
{
}

bool MinesweeperBoard::hasFlag(int row, int col) const
{
}

void MinesweeperBoard::toggleFlag(int row, int col)
{
}

void MinesweeperBoard::revealField(int row, int col)
{
}

bool MinesweeperBoard::isRevealed(int row, int col) const
{
}

GameState MinesweeperBoard::getGameState() const
{
}

char MinesweeperBoard::getFieldInfo(int row, int col) const
{
}

