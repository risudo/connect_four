#include <iostream>
#include "Board.hpp"

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
	Board b;

	b.printBoard();
	b.setPiece(1, 1, '2');
	b.printBoard();
	return 0;
}
