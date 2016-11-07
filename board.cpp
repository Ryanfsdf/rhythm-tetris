#include "board.h"

Board::Board() {
	for (int i; i < PLAY_HEIGHT; ++i) {
		for (int x; x < PLAY_WIDTH; ++x) {
			board[x][i] = 0;
		}
	}
}

Board::~Board() {

}

void Board::makePiece(Piece_Shapes piece) {
	
}

void Board::dropPiece() {

}

void Board::checkField() {
	
}