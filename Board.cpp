#include "Board.hpp"
#include <iostream>

Board::Board()
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			_map[i][j] = '0';
		}
	}
}

Board::~Board()
{
}

void Board::printBoard() const
{
	std::cout << "┌───┬───┬───┬───┬───┬───┬───┐" << std::endl;
	for (int i = 0; i < 6; i++)
	{
		std::cout << "│";
		for (int j = 0; j < 7; j++)
		{
			std::cout << " ";
			if (_map[i][j] == '1') {
				std::cout << "◯";
			} else if (_map[i][j] == '2') {
				std::cout << "×";
			} else {
				std::cout << " ";
			}
			std::cout << " │";
		}
		if (i != 5) {
			std::cout << "\n├───┼───┼───┼───┼───┼───┼───┤" << std::endl;
		} else {
			std::cout << std::endl;
		}
	}
	std::cout << "└───┴───┴───┴───┴───┴───┴───┘" << std::endl;
}

void Board::printMap() const
{
	std::cout << "--- printMap() ---" << std::endl;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			std::cout << _map[i][j];
		}
		std::cout << std::endl;
	}
	std::cout << "------------------" << std::endl;
}

void Board::setPiece(int col, int row, char piece)
{
	_map[col][row] = piece;
}
