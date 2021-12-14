#include "HUM_Player.hpp"
#include <iostream>
#include "define.hpp"
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

int HUM_Player::nb = 0;

HUM_Player::HUM_Player(Board &b, std::string name):
	_b(b), _name(name)
{
	nb++;
	_c = nb + '0';
}

HUM_Player::~HUM_Player()
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
	std::cout << "↑" << HIDE_CUR << std::flush;
}

void HUM_Player::Select()
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

			if (c == ENTER && col[pos] >= 0) {
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
	_b.setPiece(col[pos], pos, _c, _name);
	col[pos]--;
}
