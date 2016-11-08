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
void Graphics::updateScreen(/*Board * tetrisBoard*/) {
	/*Piece * currentPiece = tetrisBoard->getPiece();
	int pieceXPosition = tetrisBoard->getPieceX();
	int pieceYPosition = tetrisBoard->getPieceY();


//Segfault
    for (int y = 0; y < PLAY_HEIGHT; ++y) {
		for (int x = 0; x < PLAY_WIDTH; ++x) {
			if (((x >= pieceXPosition - 2) && (x <= pieceXPosition + 2)) &&
				((y >= pieceYPosition - 2) && (y <= pieceYPosition + 2))) {
				if (((pieceYPosition - y - 2) >= 0) && ((pieceXPosition - x - 2) >= 0) &&
					((pieceYPosition - y - 2) <= 4) && ((pieceXPosition - x - 2) <= 4)) {
					std::cout << (pieceYPosition - y - 2) << (pieceYPosition - y - 2);
					if  (currentPiece->getPiece()
							[pieceYPosition - y - 2][pieceXPosition - x - 2] == 1) {

						boxColor(render, 5, 5, 50, 50, 0xFFFFDB7F);
						
					}
				}
					
			}
		}
	}*/

    boxColor(render, 5, 5, 50, 50, 0xFFFFDB7F);


    SDL_RenderPresent(render);

    boxColor(render, 50, 50 + test , 150 , 150 + test, 0xAAFFDB7F);


    SDL_RenderPresent(render);

    SDL_SetRenderDrawColor(render, 0, 0, 0, 255);
	SDL_RenderClear(render);


	SDL_RenderPresent(render);
}
