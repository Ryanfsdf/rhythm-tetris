#include "piece.h"

#define PROGRAM_TITLE "Rhythm Tetris"
	
#define PLAY_HEIGHT 20
#define PLAY_WIDTH 10

#define HEIGHT_PIXEL 500
#define WIDTH_PIXEL 400

class Board {
private:
	int board[10][22];
	int currentPiece[5][5];
public:
	Board();
	~Board();

	void makePiece(Piece_Shapes piece);
	void dropPiece();

	void checkField();

};