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

    display = SDL_CreateTexture(render,
    	SDL_PIXELFORMAT_RGBA8888, 
    	SDL_TEXTUREACCESS_TARGET, 
    	WIDTH_PIXEL, 
    	HEIGHT_PIXEL);


    SDL_SetRenderTarget(render, display);
	SDL_RenderPresent(render);
	
}

void Graphics::updateBoard() {

    SDL_SetRenderTarget(render, NULL);
    SDL_RenderCopy(render, display, NULL, NULL);
    
    boxColor(render, 5, 5, 50, 50, 0xFFFFDB7F);


    SDL_RenderPresent(render);
}

void Graphics::closeBoard() {
    
    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(window);
    TTF_Quit();

    // Shut down SDL
    SDL_Quit();
}