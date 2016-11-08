#include "piece.h"
#include <algorithm>

Piece::Piece(){}
Piece::Piece(Piece_Shapes piece) {
	const char (*tempPiece)[PIECE_SIZE][PIECE_SIZE];

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
	for (int i = 0; i < PIECE_SIZE; ++i){
	    for (int j = 0; j < PIECE_SIZE/2; ++j){
	        std::swap(tetrisPiece[i][j], tetrisPiece[i][PIECE_SIZE-1-j]);
	    }
	}
}

char (* Piece::getPiece())[PIECE_SIZE] {
	return tetrisPiece;
}