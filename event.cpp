#include "event.h"

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
						//
					break;

					case SDLK_LEFT:
						tetrisBoard->movePieceLeft();
					break;

					case SDLK_RIGHT:
						tetrisBoard->movePieceRight();
					break;

					case SDLK_SPACE:
						//
					break;

					case SDLK_LSHIFT:
						//
					break;

					default:
						//
					break;
				}
			break;

			case SDL_KEYUP:
				//
			break;

			default:
				//
			break;
		}
	}
}
