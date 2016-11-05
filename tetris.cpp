#include "tetris.h"
#include "define.h"

void Tetris::drawField() {

	for (int i; i < PLAY_HEIGHT; ++i) {
		for (int x; x < PLAY_WIDTH; ++x) {
			board[x][i] = 0;
		}
	}
}

void Tetris::dropPiece() {

}

void Tetris::checkField() {
	
}