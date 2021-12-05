#ifndef BOARD_HPP
# define BOARD_HPP
# include <string>

class Board
{
public:
	Board();
	~Board();
	void printBoard() const;
	void setPiece(const int col, const int row, const char piece, const std::string &name);
	void printMap() const;
private:
	char _map[6][7];
	bool is_four_in_a_row(int col, int row) const;
};

#endif /* BOARD_HPP */
