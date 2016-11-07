#ifndef PIECE_H
#define PIECE_H


typedef enum {
	S_SHAPE,
	Z_SHAPE,
	LI_SHAPE,
	T_SHAPE,
	SQ_SHAPE,
	L_SHAPE,
	RL_SHAPE
} Piece_Shapes;

const char s_piece[5][5] = {
	{0,0,0,0,0},
	{0,0,1,0,0},
	{0,0,1,1,0},
	{0,0,0,1,0},
	{0,0,0,0,0}
};
const char z_piece[5][5] = {
	{0,0,0,0,0},
	{0,0,0,1,0},
	{0,0,1,1,0},
	{0,0,1,0,0},
	{0,0,0,0,0}
};
const char li_piece[5][5] = {
	{0,0,1,0,0},
	{0,0,1,0,0},
	{0,0,1,0,0},
	{0,0,1,0,0},
	{0,0,0,0,0}
};
const char t_piece[5][5] = {
	{0,0,0,0,0},
	{0,0,1,0,0},
	{0,1,1,1,0},
	{0,0,0,0,0},
	{0,0,0,0,0}
};
const char sq_piece[5][5] = {
	{0,0,0,0,0},
	{0,0,1,1,0},
	{0,0,1,1,0},
	{0,0,0,0,0},
	{0,0,0,0,0}
};
const char l_piece[5][5] = {
	{0,0,1,0,0},
	{0,0,1,0,0},
	{0,0,1,1,0},
	{0,0,0,0,0},
	{0,0,0,0,0}
};
const char rl_piece[5][5] = {
	{0,0,1,0,0},
	{0,0,1,0,0},
	{0,1,1,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0}
};

class Piece {
private:
	char tetrisPiece[5][5];
public:
	Piece(Piece_Shapes piece);
	~Piece();

	void rotatePiece();
	char (* getPiece())[5];
};

#endif