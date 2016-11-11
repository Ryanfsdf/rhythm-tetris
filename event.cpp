#include "event.h"
#include <fstream>
#include <string>

static int numClapMax = 0;

void checkEvent(Board * tetrisBoard) {
	SDL_Event event;

	while (SDL_PollEvent(&event)) {
		switch (event.type) {
			//Detect window close
			case SDL_QUIT:
				exit(0);
			break;

			case SDL_KEYDOWN:
				switch (event.key.keysym.sym) {
					case SDLK_UP:
						tetrisBoard->rotatePiece();
					break;

					case SDLK_DOWN:
						tetrisBoard->dropPiece();
					break;

					case SDLK_LEFT:
						tetrisBoard->movePieceLeft();
					break;

					case SDLK_RIGHT:
						tetrisBoard->movePieceRight();
					break;

					case SDLK_SPACE:
						tetrisBoard->dropPieceFull();
					break;

					case SDLK_LSHIFT:
						//
					break;

					case SDLK_r:
						tetrisBoard->reset();
					break;

					default:
						//
					break;
				}
			break;

			default:
				//
			break;
		}
	}
}

void checkClap(Board *tetrisBoard) {
	int numClap = 0;
	std::ifstream file("SendToC");
    std::string str; 
    while (std::getline(file, str))
    {
        ++numClap;
    }
    if (numClap > numClapMax) {
    	tetrisBoard->dropPieceFull();
    	numClapMax = numClap;
    }
}