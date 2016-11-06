#define PROGRAM_TITLE "Rhythm Tetris"
	
#define PLAY_HEIGHT 20
#define PLAY_WIDTH 10

#define HEIGHT_PIXEL 800
#define WIDTH_PIXEL 500


class Board {
private:
	int board[10][22];
public:
	Board();
	~Board();

	void drawField();
	void dropPiece();

	void checkField();

};