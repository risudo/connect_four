#include "Board.hpp"
#include <iostream>
#include "define.hpp"
#include <unistd.h>

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
	std::cout << MOVE_TOP << DELETE;
	std::cout << "┌───┬───┬───┬───┬───┬───┬───┐" << std::endl;
	for (int i = 0; i < 6; i++)
	{
		std::cout << "│";
		for (int j = 0; j < 7; j++)
		{
			std::cout << " ";
			if (_map[i][j] == '1') {
				std::cout << RED << "◯" << RESET;
			} else if (_map[i][j] == '2') {
				std::cout << GREEN << "◯" << RESET;
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
// void Board::setPiece(const int col, const int row, const char piece, const std::string &name)
// {

// }

void Board::setPiece(const int col, const int row, const char piece, const std::string &name)
{
	_map[col][row] = piece;
	if (is_four_in_a_row(col, row))
	{
		printBoard();
		std::cout << name << " WIN!!" << std::endl;
		sleep(2);
		std::exit(0);
	}
}

bool Board::is_four_in_a_row(int col, int row) const
{
	const char c = _map[col][row];

	std::cout << RED;
	// 下方向
	int cnt = 0;
	for (int i = col; i < 6; i++)
	{
		if (_map[i][row] == c)
		{
			cnt++;
			// std::cout << "col: " << i << std::endl;
			// std::cout << "row: " << row << std::endl;
			// std::cout << "cnt: " << cnt << std::endl;
		}
		if (cnt == 4)
		{
			std::cout << RESET;
			return true;
		}
	}
	// 右方向
	// 左方向
	// スラッシュ方向
	// バックスラッシュ方向

	std::cout << RESET;
	return false;
}
