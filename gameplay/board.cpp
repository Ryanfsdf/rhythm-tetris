#include "board.h"

#include <stdlib.h>
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


void Board::reset() {
	cleanBoard();
	makePiece();
	updateBoard();
}

void Board::makePiece() {
	//NULL
	if (currentPiece != 0) {
		delete currentPiece;
	}

	pieceXPosition = PLAY_WIDTH/2 - 1;
	pieceYPosition = 2;

	currentPiece =  new Piece(Piece_Shapes(rand() % 7));

	//Game Lost
	if (!isValid()) {
		reset();
	}
}

void Board::makePiece(Piece_Shapes piece) {
	//NULL
	if (currentPiece != 0) {
		delete currentPiece;
	}

	pieceXPosition = PLAY_WIDTH/2 - 1;
	pieceYPosition = 2;

	currentPiece =  new Piece(piece);

	//Game Lost
	if (!isValid()) {
		reset();
	}
}

void Board::dropPiece() {
	++pieceYPosition;
	if (!isValid()) {
		--pieceYPosition;
		solidifyBoard();
		removeFullLines();
		makePiece();
		updateBoard();
		return;
	}
	updateBoard();
}

void Board::dropPieceFull() {
	while (1) {
		++pieceYPosition;
		if (!isValid()) {
			--pieceYPosition;
			solidifyBoard();
			removeFullLines();
			makePiece();
			updateBoard();
			return;
		}
	}
}

void Board::rotatePiece() {
	currentPiece->rotatePiece();
	while (!isValid()) {
		currentPiece->rotatePiece();
	}
	updateBoard();
	//more work needs to be done here
}

void Board::movePieceLeft() {
	--pieceXPosition;
	if (!isValid()) {
		++pieceXPosition;
		return;
	}
	updateBoard();
}
	
void Board::movePieceRight() {
	++pieceXPosition;
	if (!isValid()) {
		--pieceXPosition;
		return;
	}
	updateBoard();
}

void Board::cleanBoard() {
	for (int y = 0; y < PLAY_HEIGHT; ++y) {
		for (int x = 0; x < PLAY_WIDTH; ++x) {
			board[y][x] = 0;
		}
	}
}

void Board::updateBoard() {
	for (int y = 0; y < PLAY_HEIGHT; ++y) {
		for (int x = 0; x < PLAY_WIDTH; ++x) {
			//Removes all colors
			if (board[y][x] >= 3) {
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
					board[y][x] = currentPiece->getColor();
				}
			}
		}
	}
}

void Board::solidifyBoard() {
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
					(currentPiece->getPieceAt(x + 2 - pieceXPosition, 
						y + 2 - pieceYPosition) == 1)) {
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
					if ((currentPiece->getPieceAt(x + 2 - pieceXPosition, 
						y + 2 - pieceYPosition) == 1)) {
						if (board[y][x] == 1) {
							return false;
						}
						//std::cout << "X: " << x << " || Y: " << y << "\n";
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

void Board::removeLine(int lineNum) {
	for (int y = lineNum - 1; y >= 0; y--) {
		for (int x = 0; x < PLAY_WIDTH; ++x) {
			board[y+1][x] = board[y][x];
		}
	}

}

int Board::removeFullLines() {
	int numLines = 0;
	for (int y = 0; y < PLAY_HEIGHT; y++) {
		int horizonalCount = 0;
		for (int x = 0; x < PLAY_WIDTH; ++x) {
			if (board[y][x] == 1)
			++horizonalCount;
		}
		if (horizonalCount >= PLAY_WIDTH) {
			removeLine(y);
			++numLines; 
		}
	}
	//std::cout << "Num Lines Removed: " << numLines << "\n";
	return numLines;
}
