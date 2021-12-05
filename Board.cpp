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

bool Board::check_slash(int col, int row, const char c) const
{
	int i = col;
	int j = row;
	while (i < 6 && j < 7 && _map[i][j] == c)
	{
		i++;
		j++;
	}
	int cnt = 0;
	while (i > 0 && j > 0)
	{
		if (_map[i][j] == c)
		{
			cnt++;
		}
		if (cnt == 4)
		{
			return true;
		}
		i--;
		j--;
	}
	return false;
}

bool Board::is_four_in_a_row(int col, int row) const
{
	const char c = _map[col][row];

	// 下方向
	int cnt = 0;
	for (int i = col; i < 6; i++)
	{
		if (_map[i][row] == c)
		{
			cnt++;
		}
		if (cnt == 4)
		{
			return true;
		}
	}

	// 横方向
	cnt = 0;
	int i;
	for (i = row; i < 7; i++)
	{
		if (_map[col][i] != c)
		{
			break ;
		}
	}
	for (int j= i; j >= 0; j--)
	{
		if (_map[col][j] == c)
		{
			cnt++;
		}
		if (cnt == 4)
		{
			return true;
		}
	}
	// スラッシュ方向
	if (check_slash(col, row, c))
	{
		return true;
	}
	// バックスラッシュ方向

	std::cout << RESET;
	return false;
}
