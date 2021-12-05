#include <iostream>
#include "Board.hpp"
#include "MainPlayer.hpp"
#include "define.hpp"

// TODO: 縦の入力数のバリデーション
// TODO: 名前入力
int main()
{
	std::cout << CLEAR << MOVE_TOP;
	Board b;
	MainPlayer p1(b, "rsudo");
	MainPlayer p2(b, "hoge");

	while (1)
	{
		p1.Select();
		p2.Select();
	}
	return 0;
}
