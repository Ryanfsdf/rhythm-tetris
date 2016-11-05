

class Tetris {
private:
	int board[10][22];
public:
	Tetris();
	~Tetris();

	void drawField();
	void dropPiece();

	void checkField();

};