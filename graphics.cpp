#include "graphics.h"
#include <iostream>

Graphics::Graphics() {
    window = SDL_CreateWindow(PROGRAM_TITLE,
    	SDL_WINDOWPOS_CENTERED, 
        SDL_WINDOWPOS_CENTERED,
        WIDTH_PIXEL, 
        HEIGHT_PIXEL,
        SDL_WINDOW_SHOWN);

    render = SDL_CreateRenderer(window, 
    	-1, 
    	SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE);

    SDL_SetRenderDrawBlendMode(render, SDL_BLENDMODE_BLEND);

	SDL_SetRenderDrawColor(render, 0, 0, 0, 255);

	SDL_RenderClear(render);

	SDL_RenderPresent(render);
}

Graphics::~Graphics() {
	SDL_DestroyRenderer(render);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

#define test 0
void Graphics::updateScreen(Board * tetrisBoard) {
	Piece * currentPiece = tetrisBoard->getPiece();
	int pieceXPosition = tetrisBoard->getPieceX();
	int pieceYPosition = tetrisBoard->getPieceY();


    for (int y = 0; y < PLAY_HEIGHT; ++y) {
		for (int x = 0; x < PLAY_WIDTH; ++x) {
			if (((x >= pieceXPosition - 2) && (x <= pieceXPosition + 2)) &&
				((y >= pieceYPosition - 2) && (y <= pieceYPosition + 2))) {

				std::cout << (currentPiece->getPieceAt(pieceYPosition - y - 2, pieceXPosition - x - 2) == 0);
				std::cout << "X: " << (x + 2 - pieceXPosition) << "|| Y: " << (y + 2 - pieceYPosition) << "\n";

				if (((y + 2 - pieceYPosition) >= 0) && ((x + 2 - pieceXPosition) >= 0) &&
					((y + 2 - pieceYPosition) <= 4) && ((x + 2 - pieceXPosition) <= 4) &&
					(currentPiece->getPieceAt(x + 2 - pieceXPosition, y + 2 - pieceYPosition) == 1)) {
					boxColor(render, WIDTH_PIXEL/PLAY_WIDTH * x, HEIGHT_PIXEL/PLAY_HEIGHT * y,
					WIDTH_PIXEL/PLAY_WIDTH * (x + 1), HEIGHT_PIXEL/PLAY_HEIGHT * (y + 1), 0xFFFFDB7F);

				}
			}
		}
	}

	std::cout << "****************************\n";
    
    SDL_RenderPresent(render);

}
