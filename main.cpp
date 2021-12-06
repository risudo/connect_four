#include <iostream>
#include "Board.hpp"
#include "HUM_Player.hpp"
#include "define.hpp"

// TODO: 名前入力
// TODO: << のオーバーロード

std::string input_name()
{
	static int n;

	n++;

	std::cout << "Enter Player" << n << " name > " << std::flush;
	std::string name;
	std::getline(std::cin, name);
	if (!std::cin)
	{
		std::exit(1);
	}
	return name;
}

int main()
{
	std::cout << CLEAR << MOVE_TOP;
	Board b;
	std::string name1 = input_name();
	std::string name2 = input_name();
	HUM_Player p1(b, name1);
	HUM_Player p2(b, name2);

	while (1)
	{
		p1.Select();
		p2.Select();
	}
	return 0;
}
