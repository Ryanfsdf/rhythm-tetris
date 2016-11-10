#include "piece.h"

Piece::Piece(Piece_Shapes piece) {
	const int (*tempPiece)[PIECE_SIZE][PIECE_SIZE];

	switch (piece) {
		case S_SHAPE:
			tempPiece = &s_piece;
		break;

		case Z_SHAPE:
			tempPiece = &z_piece;
		break;

		case LI_SHAPE:
			tempPiece = &li_piece;
		break;

		case T_SHAPE:
			tempPiece = &t_piece;
		break;

		case SQ_SHAPE:
			tempPiece = &sq_piece;
		break;

		case L_SHAPE:
			tempPiece = &l_piece;
		break;

		case RL_SHAPE:
			tempPiece = &rl_piece;
		break;

		default:
		break;
	}

	for (int i = 0; i < PIECE_SIZE; ++i) {
		for (int j = 0; j < PIECE_SIZE; ++j){
			tetrisPiece[i][j] = (*tempPiece)[i][j];
		}
	}
}

Piece::~Piece(){}

void Piece::rotatePiece() {
	for(int i = 0; i < PIECE_SIZE / 2; i++) {
		for(int j = 0; j < (PIECE_SIZE + 1) / 2; j++) {
			rollHelper(tetrisPiece[i][j], tetrisPiece[PIECE_SIZE - 1 - j][i], 
				tetrisPiece[PIECE_SIZE - 1 - i][PIECE_SIZE - 1 - j], 
				tetrisPiece[j][PIECE_SIZE - 1 - i]);
		}
	}
}

void Piece::rollHelper(int &a, int &b, int &c, int &d)
{
   int temp = a;
   a = b;
   b = c;
   c = d;
   d = temp;
}

int Piece::getPieceAt(int x, int y) {
	return tetrisPiece[y][x];
}