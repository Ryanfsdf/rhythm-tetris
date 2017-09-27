#ifndef PIECE_H
#define PIECE_H

//must change the arrays if you change the piece size
const int PIECE_SIZE = 5;

const int LIME  = 3;
const int RED = 4;
const int TEAL = 5;
const int PURPLE = 6;
const int YELLOW = 7;
const int ORANGE = 8;
const int BLUE = 9;

enum Piece_Shapes {
	S_SHAPE,
	Z_SHAPE,
	LI_SHAPE,
	T_SHAPE,
	SQ_SHAPE,
	L_SHAPE,
	RL_SHAPE
};

const int s_piece[PIECE_SIZE][PIECE_SIZE] = {
	{0,0,0,0,0},
	{0,0,1,1,0},
	{0,1,1,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0}
};
const int z_piece[PIECE_SIZE][PIECE_SIZE] = {
	{0,0,0,0,0},
	{0,1,1,0,0},
	{0,0,1,1,0},
	{0,0,0,0,0},
	{0,0,0,0,0}
};
const int li_piece[PIECE_SIZE][PIECE_SIZE] = {
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,1,1,1,1},
	{0,0,0,0,0},
	{0,0,0,0,0}
};
const int t_piece[PIECE_SIZE][PIECE_SIZE] = {
	{0,0,0,0,0},
	{0,0,1,0,0},
	{0,1,1,1,0},
	{0,0,0,0,0},
	{0,0,0,0,0}
};
const int sq_piece[PIECE_SIZE][PIECE_SIZE] = {
	{0,0,0,0,0},
	{0,0,1,1,0},
	{0,0,1,1,0},
	{0,0,0,0,0},
	{0,0,0,0,0}
};
const int l_piece[PIECE_SIZE][PIECE_SIZE] = {
	{0,0,0,0,0},
	{0,0,0,1,0},
	{0,1,1,1,0},
	{0,0,0,0,0},
	{0,0,0,0,0}
};
const int rl_piece[PIECE_SIZE][PIECE_SIZE] = {
	{0,0,0,0,0},
	{0,1,0,0,0},
	{0,1,1,1,0},
	{0,0,0,0,0},
	{0,0,0,0,0}
};

class Piece {
private:
	int tetrisPiece[PIECE_SIZE][PIECE_SIZE];
	int pieceColor;
	void rotateHelper (int &a, int &b, int &c, int &d);

public:
	Piece(Piece_Shapes piece);
	~Piece();

	void rotatePiece();
	int getPieceAt(int x, int y);
	int getColor();
};

#endif