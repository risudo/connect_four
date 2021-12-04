#include "MainPlayer.hpp"
#include <iostream>
#include "define.hpp"

int MainPlayer::cnt = 0;

MainPlayer::MainPlayer(Board &b, std::string name):
	_b(b), _name(name)
{
	cnt++;
	c = cnt + '0';
}

MainPlayer::~MainPlayer()
{
}

void MainPlayer::Select()
{
	std::cout << MOVE_TOP << DELETE;
	static int col[7] = {5, 5, 5, 5, 5, 5, 5};

	_b.printBoard();
	std::cout << " (1) (2) (3) (4) (5) (6) (7)\n" << std::endl;
	std::cout << "TURN: < " << _name << " >" << std::endl;
	std::cout << "Select number 1 ~ 7 > " << std::flush;

	std::string nb;
	std::getline(std::cin, nb);
	// validate
	// Set
	int row = nb[0] - '0' - 1;
	_b.setPiece(col[row], row, c);
	// static インクリメント
	row[col]--;
}
