#include <iostream>
#include "Board.hpp"
#include "MainPlayer.hpp"
#include "define.hpp"

// TODO: 名前入力
// TODO: << のオーバーロード
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
