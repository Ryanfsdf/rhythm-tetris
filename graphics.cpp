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

void Graphics::updateScreen(Board * tetrisBoard) {
    for (int y = 0; y < PLAY_HEIGHT; ++y) {
		for (int x = 0; x < PLAY_WIDTH; ++x) {
			//std::cout << tetrisBoard->getBoardAt(x,y);
			if (tetrisBoard->getBoardAt(x,y) == 2) {
				boxColor(render, WIDTH_PIXEL/PLAY_WIDTH * x, HEIGHT_PIXEL/PLAY_HEIGHT * y, 
					WIDTH_PIXEL/PLAY_WIDTH * (x + 1), HEIGHT_PIXEL/PLAY_HEIGHT * (y + 1), 0xFFFFDB7F);
			}
			else if (tetrisBoard->getBoardAt(x,y) == 1) {
				boxColor(render, WIDTH_PIXEL/PLAY_WIDTH * x, HEIGHT_PIXEL/PLAY_HEIGHT * y,
					WIDTH_PIXEL/PLAY_WIDTH * (x + 1), HEIGHT_PIXEL/PLAY_HEIGHT * (y + 1), 0xFF333333);
			}
			else {
				boxColor(render, WIDTH_PIXEL/PLAY_WIDTH * x, HEIGHT_PIXEL/PLAY_HEIGHT * y,
					WIDTH_PIXEL/PLAY_WIDTH * (x + 1), HEIGHT_PIXEL/PLAY_HEIGHT * (y + 1), 0xFF000000);
			}
		}
	}

	//std::cout << "****************************" << count << "\n";
    
    SDL_RenderPresent(render);

}
