#include "piece.h"
#include <algorithm>

Piece::Piece(Piece_Shapes piece) {
	const char (*tempPiece)[5][5];

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

	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j){
			tetrisPiece[i][j] = (*tempPiece)[i][j];
		}
	}
}

Piece::~Piece(){}

void Piece::rotatePiece() {
	for (int i = 0; i < 5; ++i){
	    for (int j = 0; j < 2; ++j){
	        std::swap(tetrisPiece[i][j], tetrisPiece[i][5-1-j]);
	    }
	}
}

char (* Piece::getPiece())[5] {
	return tetrisPiece;
}