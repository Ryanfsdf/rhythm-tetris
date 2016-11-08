#ifndef PIECE_H
#define PIECE_H

//must change the arrays if you change the piece size
#define PIECE_SIZE 5

typedef enum {
	S_SHAPE,
	Z_SHAPE,
	LI_SHAPE,
	T_SHAPE,
	SQ_SHAPE,
	L_SHAPE,
	RL_SHAPE
} Piece_Shapes;

const char s_piece[PIECE_SIZE][PIECE_SIZE] = {
	{0,0,0,0,0},
	{0,0,1,0,0},
	{0,0,1,1,0},
	{0,0,0,1,0},
	{0,0,0,0,0}
};
const char z_piece[PIECE_SIZE][PIECE_SIZE] = {
	{0,0,0,0,0},
	{0,0,0,1,0},
	{0,0,1,1,0},
	{0,0,1,0,0},
	{0,0,0,0,0}
};
const char li_piece[PIECE_SIZE][PIECE_SIZE] = {
	{0,0,1,0,0},
	{0,0,1,0,0},
	{0,0,1,0,0},
	{0,0,1,0,0},
	{0,0,0,0,0}
};
const char t_piece[PIECE_SIZE][PIECE_SIZE] = {
	{0,0,0,0,0},
	{0,0,1,0,0},
	{0,1,1,1,0},
	{0,0,0,0,0},
	{0,0,0,0,0}
};
const char sq_piece[PIECE_SIZE][PIECE_SIZE] = {
	{0,0,0,0,0},
	{0,0,1,1,0},
	{0,0,1,1,0},
	{0,0,0,0,0},
	{0,0,0,0,0}
};
const char l_piece[PIECE_SIZE][PIECE_SIZE] = {
	{0,0,1,0,0},
	{0,0,1,0,0},
	{0,0,1,1,0},
	{0,0,0,0,0},
	{0,0,0,0,0}
};
const char rl_piece[PIECE_SIZE][PIECE_SIZE] = {
	{0,0,1,0,0},
	{0,0,1,0,0},
	{0,1,1,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0}
};

class Piece {
private:
	char tetrisPiece[PIECE_SIZE][PIECE_SIZE];
public:
	Piece(Piece_Shapes piece);
	~Piece();

	void rotatePiece();
	char (* getPiece())[PIECE_SIZE];
};

#endif