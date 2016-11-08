#include "board.h"

Board::Board() {
	for (int i; i < PLAY_HEIGHT; ++i) {
		for (int x; x < PLAY_WIDTH; ++x) {
			board[i][x] = 0;
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
	for (int i = 0; i < PLAY_HEIGHT; ++i) {
		for (int x = 0; x < PLAY_WIDTH; ++x) {
			
		}
	}

}

void Board::checkField() {
	//make new piece ff checkField shows that piece has dropped fully	
}