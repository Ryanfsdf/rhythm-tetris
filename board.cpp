#include "board.h"
#include "define.h"

Board::Board() {

}

Board::~Board() {

}

void Board::drawField() {

	for (int i; i < PLAY_HEIGHT; ++i) {
		for (int x; x < PLAY_WIDTH; ++x) {
			board[x][i] = 0;
		}
	}
}

void Board::dropPiece() {

}

void Board::checkField() {
	
}