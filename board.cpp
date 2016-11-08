#include "board.h"

Board::Board() {
	for (int y; y < PLAY_HEIGHT; ++y) {
		for (int x; x < PLAY_WIDTH; ++x) {
			board[y][x] = 0;
		}
	}

	makePiece();
}

Board::~Board() {
	//NULL
	if (currentPiece != 0) {
		delete currentPiece;
	}
}

char Board::getBoardAt(int x, int y) {
	return board[y][x];
}

int Board::getPieceX() {
	return pieceXPosition;
}

int Board::getPieceY() {
	return pieceYPosition;
}

void Board::makePiece() {
	//NULL
	if (currentPiece != 0) {
		delete currentPiece;
	}

	pieceXPosition = PLAY_WIDTH/2;
	pieceYPosition = 2;

	//MAKE THIS RANDOM : TODO
	currentPiece =  new Piece(S_SHAPE);
}

void Board::makePiece(Piece_Shapes piece) {
	//NULL
	if (currentPiece != 0) {
		delete currentPiece;
	}

	pieceXPosition = PLAY_WIDTH/2;
	pieceYPosition = 2;

	currentPiece =  new Piece(piece);
}

Piece * Board::getPiece() {
	return currentPiece;
}

void Board::dropPiece() {
	++pieceYPosition;
	if (!isValid()) {
		solidifyBoard();
		makePiece();
	}
}

void Board::updateBoard() {
	for (int y = 0; y < PLAY_HEIGHT; ++y) {
		for (int x = 0; x < PLAY_WIDTH; ++x) {
			if (board[y][x] == 2) {
				board[y][x] = 0;
			}
		}
	}
	for (int y = 0; y < PLAY_HEIGHT; ++y) {
		for (int x = 0; x < PLAY_WIDTH; ++x) {
			if (((x >= pieceXPosition - 2) && (x <= pieceXPosition + 2)) &&
				((y >= pieceYPosition - 2) && (y <= pieceYPosition + 2))) {
				if (((pieceYPosition - y - 2) >= 0) && ((pieceXPosition - x - 2) >= 0) &&
					(currentPiece->getPieceAt(pieceYPosition - y - 2, pieceXPosition - x - 2) == 1)){
					board[y][x] = 2;
				}
			}
		}
	}
}

void Board::solidifyBoard() {
	for (int y = 0; y < PLAY_HEIGHT; ++y) {
		for (int x = 0; x < PLAY_WIDTH; ++x) {
			if (((x >= pieceXPosition - 2) && (x <= pieceXPosition + 2)) &&
				((y >= pieceYPosition - 2) && (y <= pieceYPosition + 2))) {
				if (((pieceYPosition - y - 2) >= 0) && ((pieceXPosition - x - 2) >= 0) &&
					(currentPiece->getPieceAt(pieceYPosition - y - 2, pieceXPosition - x - 2) == 1)){
					board[y][x] = 1;
				}
			}
		}
	}
}

bool Board::isValid() {
	for (int y = 0; y < PLAY_HEIGHT; ++y) {
		for (int x = 0; x < PLAY_WIDTH; ++x) {
			if (((x >= pieceXPosition - 2) && (x <= pieceXPosition + 2)) &&
				((y >= pieceYPosition - 2) && (y <= pieceYPosition + 2))) {
				if (((pieceYPosition - y - 2) >= 0) && ((pieceXPosition - x - 2) >= 0) &&
					(currentPiece->getPieceAt(pieceYPosition - y - 2, pieceXPosition - x - 2) == 1)) {
					if (board[y][x] == 1) {
						return false;
					}
				}
			}
		}
	}
	return true;
}