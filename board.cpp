#include "board.h"

Board::Board() {
	for (int y; y < PLAY_HEIGHT; ++y) {
		for (int x; x < PLAY_WIDTH; ++x) {
			board[y][x] = 0;
		}
	}

	pieceXPosition = PLAY_WIDTH/2;
	pieceYPosition = 2;
}

Board::~Board() {
	//NULL
	if (currentPiece != 0) {
		delete currentPiece;
	}
}

void Board::makePiece(Piece_Shapes piece) {
	//NULL
	if (currentPiece != 0) {
		delete currentPiece;
	}

	currentPiece =  new Piece(piece);
}

void Board::dropPiece() {
	++pieceYPosition;
	updateBoard();
	checkField(); 
}

void Board::updateBoard() {
	for (int y = 0; y < PLAY_HEIGHT; ++y) {
		for (int x = 0; x < PLAY_WIDTH; ++x) {
			if (((x >= pieceXPosition - 2) && (x <= pieceXPosition + 2)) &&
				((y >= pieceYPosition - 2) && (y <= pieceYPosition + 2))) {
				if ((currentPiece->getPiece())
					[pieceYPosition - y - 2][pieceXPosition - x - 2] == 1) {
					board[y][x] = 2;
				}
			}
		}
	}

}

void Board::checkField() {
	//make new piece ff checkField shows that piece has dropped fully	
}