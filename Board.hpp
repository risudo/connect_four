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
private:
	char _map[6][7];
	bool is_four_in_a_row(int col, int row) const;
	bool check_downward(int col, int row, const char c) const;
	bool check_horizontal(int col, int row, const char c) const;
	bool check_slash_direction(int col, int row, const char c) const;
	bool check_backslash_direction(int col, int row, const char c) const;
};

#endif /* BOARD_HPP */
