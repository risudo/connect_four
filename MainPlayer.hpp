#ifndef MAINPLAYER_HPP
# define MAINPLAYER_HPP
# include "Board.hpp"
# include <string>

class MainPlayer
{
public:
	MainPlayer(Board &b, std::string name);
	~MainPlayer();
	void Select();
private:
	Board &_b;
	std::string _name;
	char c;
	static int cnt;
};

#endif /* MAINPLAYER_HPP */
