#include "piece.h"

#define PROGRAM_TITLE "Rhythm Tetris"
	
#define PLAY_HEIGHT 20
#define PLAY_WIDTH 10

#define HEIGHT_PIXEL 500
#define WIDTH_PIXEL 400

class Board {
private:
	int board[PLAY_HEIGHT][PLAY_WIDTH];
	Piece * currentPiece;
public:
	Board();
	~Board();

	void makePiece(Piece_Shapes piece);
	void dropPiece();

	void checkField();

};