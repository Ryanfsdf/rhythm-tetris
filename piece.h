
typedef enum {
	S_SHAPE,
	Z_SHAPE,
	LI_SHAPE,
	T_SHAPE,
	SQ_SHAPE,
	L_SHAPE,
	RL_SHAPE
} Piece_Shapes;

const int s_piece[5][5] = {
	{0,0,0,0,0},
	{0,0,1,0,0},
	{0,0,1,1,0},
	{0,0,0,1,0},
	{0,0,0,0,0}
};
const int z_piece[5][5] = {
	{0,0,0,0,0},
	{0,0,0,1,0},
	{0,0,1,1,0},
	{0,0,1,0,0},
	{0,0,0,0,0}
};
const int li_piece[5][5] = {
	{0,0,1,0,0},
	{0,0,1,0,0},
	{0,0,1,0,0},
	{0,0,1,0,0},
	{0,0,0,0,0}
};
const int t_piece[5][5] = {
	{0,0,0,0,0},
	{0,0,1,0,0},
	{0,1,1,1,0},
	{0,0,0,0,0},
	{0,0,0,0,0}
};
const int sq_piece[5][5] = {
	{0,0,0,0,0},
	{0,0,1,1,0},
	{0,0,1,1,0},
	{0,0,0,0,0},
	{0,0,0,0,0}
};
const int l_piece[5][5] = {
	{0,0,1,0,0},
	{0,0,1,0,0},
	{0,0,1,1,0},
	{0,0,0,0,0},
	{0,0,0,0,0}
};
const int rl_piece[5][5] = {
	{0,0,1,0,0},
	{0,0,1,0,0},
	{0,1,1,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0}
};

class Piece {
private:
	
public:
	Piece();
	~Piece();

	Piece rotatePiece(Piece piece);
	Piece getPiece(Piece_Shapes piece);
};