#include "graphics.h"
#include <iostream>

Graphics::Graphics() {
    window = SDL_CreateWindow(PROGRAM_TITLE,
    	SDL_WINDOWPOS_CENTERED, 
        SDL_WINDOWPOS_CENTERED,
        WIDTH_PIXEL + 200, 
        HEIGHT_PIXEL,
        SDL_WINDOW_SHOWN);

    render = SDL_CreateRenderer(window, 
    	-1, 
    	SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE);

    SDL_SetRenderDrawBlendMode(render, SDL_BLENDMODE_BLEND);


	SDL_SetRenderDrawColor(render, 0, 0, 0, 255);

	SDL_RenderClear(render);

	boxColor(render, WIDTH_PIXEL, 0, 
		WIDTH_PIXEL + 300, HEIGHT_PIXEL, 0xFF333333);

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
			Uint32 color = 0xFF000000;
			if (tetrisBoard->getBoardAt(x,y) == 1) {
				color = 0xFF555555;
			}
			else if (tetrisBoard->getBoardAt(x,y) == LIME) {
				color = 0xFF1AA114;
			}
			else if (tetrisBoard->getBoardAt(x,y) == RED) {
				color = 0xFFEA2A01;
			}
			else if (tetrisBoard->getBoardAt(x,y) == TEAL) {
				color = 0xFFFFDB7F;
			}
			else if (tetrisBoard->getBoardAt(x,y) == PURPLE) {
				color = 0xFF990077;
			}
			else if (tetrisBoard->getBoardAt(x,y) == YELLOW) {
				color = 0xFF44CEFF;
			}
			else if (tetrisBoard->getBoardAt(x,y) == ORANGE) {
				color = 0xFFE99514;
			}
			else if (tetrisBoard->getBoardAt(x,y) == BLUE) {
				color = 0xFF1B35DE;
			}
			else {
				
			}
			
			boxColor(render, WIDTH_PIXEL/PLAY_WIDTH * x, HEIGHT_PIXEL/PLAY_HEIGHT * y,
					WIDTH_PIXEL/PLAY_WIDTH * (x + 1), HEIGHT_PIXEL/PLAY_HEIGHT * (y + 1), color);
		}
	}

	//std::cout << "****************************" << count << "\n";
    
    SDL_RenderPresent(render);

}
