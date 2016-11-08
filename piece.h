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

const int s_piece[PIECE_SIZE][PIECE_SIZE] = {
	{0,0,0,0,0},
	{0,0,1,0,0},
	{0,0,1,1,0},
	{0,0,0,1,0},
	{0,0,0,0,0}
};
const int z_piece[PIECE_SIZE][PIECE_SIZE] = {
	{0,0,0,0,0},
	{0,0,0,1,0},
	{0,0,1,1,0},
	{0,0,1,0,0},
	{0,0,0,0,0}
};
const int li_piece[PIECE_SIZE][PIECE_SIZE] = {
	{0,0,1,0,0},
	{0,0,1,0,0},
	{0,0,1,0,0},
	{0,0,1,0,0},
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
	{0,0,1,0,0},
	{0,0,1,0,0},
	{0,0,1,1,0},
	{0,0,0,0,0},
	{0,0,0,0,0}
};
const int rl_piece[PIECE_SIZE][PIECE_SIZE] = {
	{0,0,1,0,0},
	{0,0,1,0,0},
	{0,1,1,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0}
};

class Piece {
private:
	int tetrisPiece[PIECE_SIZE][PIECE_SIZE];
public:
	Piece(Piece_Shapes piece);
	~Piece();

	void rotatePiece();
	int getPieceAt(int x, int y);
};

#endif