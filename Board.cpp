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

void Board::setPiece(const int col, const int row, const char piece, const std::string &name)
{
	static int cnt;

	_map[col][row] = piece;
	cnt++;
	if (is_four_in_a_row(col, row))
	{
		printBoard();
		std::cout << "\n" << name << " WIN!!" << std::endl;
		sleep(1);
		std::exit(0);
	}
	if (cnt == 42)
	{
		printBoard();
		std::cout << "\nDRAW!" << std::endl;
		sleep(1);
		std::exit(0);
	}
}

bool Board::check_downward(int col, int row, const char c) const
{
	int cnt = 0;

	for (int i = col; i < 6; i++)
	{
		if (_map[i][row] == c) {
			cnt++;
		} else {
			cnt = 0;
		}
		if (cnt == 4)
		{
			return true;
		}
	}
	return false;
}

bool Board::check_horizontal(int col, int row, const char c) const
{
	int cnt = 0;
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
		if (_map[col][j] == c) {
			cnt++;
		} else {
			cnt = 0;
		}
		if (cnt == 4)
		{
			return true;
		}
	}
	return false;
}

bool Board::check_slash_direction(int col, int row, const char c) const
{
	int i = col;
	int j = row;
	while (i < 6 && j > 0 && _map[i][j] == c)
	{
		i++;
		j--;
	}
	int cnt = 0;
	while (i > 0 && j < 7)
	{
		if (_map[i][j] == c) {
			cnt++;
		} else {
			cnt = 0;
		}
		if (cnt == 4)
		{
			return true;
		}
		i--;
		j++;
	}
	return false;
}

bool Board::check_backslash_direction(int col, int row, const char c) const
{
	int cnt = 0;
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
		if (_map[col][j] == c) {
			cnt++;
		} else {
			cnt = 0;
		}
		if (cnt == 4)
		{
			return true;
		}
	}
	return false;
}

bool Board::is_four_in_a_row(int col, int row) const
{
	const char c = _map[col][row];

	if (check_downward(col, row, c))
	{
		return true;
	}
	if (check_horizontal(col, row, c))
	{
		return true;
	}
	if (check_slash_direction(col, row, c))
	{
		return true;
	}
	if (check_backslash_direction(col, row, c))
	{
		return true;
	}
	return false;
}
