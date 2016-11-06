#include "graphics.h"
#include "board.h"

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

	SDL_SetRenderDrawColor(render, 255, 0, 0, 255);

	SDL_RenderClear(render);

	SDL_RenderPresent(render);
	
}

void Graphics::updateScreen() {

    
    boxColor(render, 5, 5, 50, 50, 0xFFFFDB7F);


    SDL_RenderPresent(render);
}

void Graphics::closeScreen() {
    
    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(window);
    TTF_Quit();

    // Shut down SDL
    SDL_Quit();
}