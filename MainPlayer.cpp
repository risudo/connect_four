#include "MainPlayer.hpp"
#include <iostream>
#include "define.hpp"
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

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

int kbhit(void)
{
	struct termios oldt, newt;
	int ch;
	int oldf;

	tcgetattr(STDIN_FILENO, &oldt);
	newt = oldt;
	newt.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);
	oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
	fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

	ch = getchar();

	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
	fcntl(STDIN_FILENO, F_SETFL, oldf);

	if (ch != EOF)
	{
		ungetc(ch, stdin);
		return 1;
	}

	return 0;
}

void put_arrow(int pos)
{
	std::cout << "\033[14;1H" << DELETE_LINE;
	std::cout << "\033[14;" << pos * 4 + 3 << "H";
	std::cout << "↑" << std::flush;
}

void MainPlayer::Select()
{
	static int col[7] = {5, 5, 5, 5, 5, 5, 5};

	_b.printBoard();
	std::cout << "\n\n" << _name << "'s turn" << std::endl;
	std::cout << "Press A, D and ENTER" << std::endl;
	int pos = 0;
	put_arrow(pos);
	while (1)
	{
		if (kbhit())
		{
			int c = getchar();

			if (c == ENTER) {
				std::cout << "enter" << std::endl;
				break ;
			} else if (c == A && pos > 0) {
				pos--;
				put_arrow(pos);
			} else if (c == D && pos < 6) {
				pos++;
				put_arrow(pos);
			} else {
				put_arrow(pos);
			}

		}
	}

	// std::cout << " (1) (2) (3) (4) (5) (6) (7)\n" << std::endl;
	// std::cout << "TURN: < " << _name << " >" << std::endl;
	// std::cout << "Select number 1 ~ 7 > " << std::flush;

	// int row = nb[0] - '0' - 1;
	_b.setPiece(col[pos], pos, c, _name);
	// static インクリメント
	col[pos]--;
}
