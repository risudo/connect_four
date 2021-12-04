#include <iostream>
#include "Board.hpp"
#include "MainPlayer.hpp"
#include "define.hpp"

void print_board()
{
	std::cout << "┌───┬───┬───┬───┬───┬───┬───┐" << std::endl;
	std::cout << "│   │   │   │   │   │   │   │" << std::endl;
	std::cout << "├───┼───┼───┼───┼───┼───┼───┤" << std::endl;
	std::cout << "│   │   │   │   │   │   │   │" << std::endl;
	std::cout << "├───┼───┼───┼───┼───┼───┼───┤" << std::endl;
	std::cout << "│   │   │   │   │   │   │   │" << std::endl;
	std::cout << "├───┼───┼───┼───┼───┼───┼───┤" << std::endl;
	std::cout << "│   │   │   │   │   │   │   │" << std::endl;
	std::cout << "├───┼───┼───┼───┼───┼───┼───┤" << std::endl;
	std::cout << "│   │   │   │   │   │   │   │" << std::endl;
	std::cout << "├───┼───┼───┼───┼───┼───┼───┤" << std::endl;
	std::cout << "│   │   │   │   │   │   │   │" << std::endl;
	std::cout << "└───┴───┴───┴───┴───┴───┴───┘" << std::endl;
}

int main()
{
	std::cout << CLEAR << MOVE_TOP;
	Board b;
	MainPlayer p1(b, "rsudo");
	MainPlayer p2(b, "a");

	while (1)
	{
		p1.Select();
		p2.Select();
	}
	return 0;
}
