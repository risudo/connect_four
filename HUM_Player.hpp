#ifndef HUM_Player_HPP
# define HUM_Player_HPP
# include "Board.hpp"
# include <string>

class HUM_Player
{
public:
	HUM_Player(Board &b, std::string name);
	~HUM_Player();
	void Select();
private:
	Board &_b;
	std::string _name;
	char _c;
	static int nb;
};

#endif /* HUM_Player_HPP */
