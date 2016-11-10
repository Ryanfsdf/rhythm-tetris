#include "board.h"
#include <iostream>

Board::Board() {
	for (int y = 0; y < PLAY_HEIGHT; ++y) {
		for (int x = 0; x < PLAY_WIDTH; ++x) {
			board[y][x] = 0;
		}
	}

	makePiece();
	updateBoard();
}

Board::~Board() {
	//NULL
	if (currentPiece != 0) {
		delete currentPiece;
	}
}

int Board::getBoardAt(int x, int y) {
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

	pieceXPosition = PLAY_WIDTH/2 - 1;
	pieceYPosition = 2;

	//MAKE THIS RANDOM : TODO
	currentPiece =  new Piece(T_SHAPE);
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

void Board::dropPiece() {
	++pieceYPosition;
	if (!isValid()) {
		--pieceYPosition;
		updateBoard();
		solidifyBoard();
		makePiece();
		return;
	}
	updateBoard();
}

void Board::rotatePiece() {
	currentPiece->rotatePiece();
	updateBoard();
	//more work needs to be done here
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

				if (((y + 2 - pieceYPosition) >= 0) && ((x + 2 - pieceXPosition) >= 0) &&
					((y + 2 - pieceYPosition) <= 4) && ((x + 2 - pieceXPosition) <= 4) &&
					(currentPiece->getPieceAt(x + 2 - pieceXPosition, y + 2 - pieceYPosition) == 1)) {
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

				if (((y + 2 - pieceYPosition) >= 0) && ((x + 2 - pieceXPosition) >= 0) &&
					((y + 2 - pieceYPosition) <= 4) && ((x + 2 - pieceXPosition) <= 4) &&
					(currentPiece->getPieceAt(x + 2 - pieceXPosition, y + 2 - pieceYPosition) == 1)) {
					board[y][x] = 1;
				}
			}
		}
	}
}

bool Board::isValid() {
	//Boundaries are extended to check out-of-board conditions
	for (int y = 0; y < PLAY_HEIGHT + 1; ++y) {
		for (int x = -1; x < PLAY_WIDTH + 1; ++x) {
			if (((x >= pieceXPosition - 2) && (x <= pieceXPosition + 2)) &&
				((y >= pieceYPosition - 2) && (y <= pieceYPosition + 2))) {

				if (((y + 2 - pieceYPosition) >= 0) && ((x + 2 - pieceXPosition) >= 0) &&
					((y + 2 - pieceYPosition) <= 4) && ((x + 2 - pieceXPosition) <= 4)) {
					if ((currentPiece->getPieceAt(x + 2 - pieceXPosition, y + 2 - pieceYPosition) == 1)) {
						if (board[y][x] == 1) {
							return false;
						}
						std::cout << "X: " << x << " || Y: " << y << "\n";
						if (y >= PLAY_HEIGHT) {
							return false;
						}
						if (x >= PLAY_WIDTH || x < 0) {
							return false;
						}
					}
				}	
			}
		}
	}
	return true;
}