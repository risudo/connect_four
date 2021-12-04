#ifndef BOARD_HPP
# define BOARD_HPP

class Board
{
public:
	Board();
	~Board();
	void printBoard() const;
	void setPiece(const int col, const int row, const char piece);
	void printMap() const;
private:
	char _map[6][7];
};

#endif /* BOARD_HPP */
