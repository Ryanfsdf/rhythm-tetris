#include "piece.h"

#define PROGRAM_TITLE "Rhythm Tetris"
	
#define PLAY_HEIGHT 20
#define PLAY_WIDTH 10

#define HEIGHT_PIXEL 600
#define WIDTH_PIXEL 300

class Board {
private:
	int board[PLAY_HEIGHT][PLAY_WIDTH];
	Piece * currentPiece = 0;

	// (0,0) is top left corner
	int pieceXPosition;
	int pieceYPosition;

public:
	Board();
	~Board();

	int getBoardAt(int x, int y);
	int getPieceX();
	int getPieceY();
	//no argument makes random piece
	void makePiece();
	void makePiece(Piece_Shapes piece);
	void dropPiece();
	void dropPieceFull();
	void rotatePiece();
	void movePieceLeft();
	void movePieceRight();
	void updateBoard();
	void solidifyBoard();
	bool isValid();
	void removeLine(int lineNum);
	int removeFullLines();

};