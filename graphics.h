#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "board.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL2_gfxPrimitives.h"

class Graphics {
private:
	SDL_Window *window;
	SDL_Renderer *render;
public:
	Graphics();
	~Graphics();

	void updateScreen(/*Board * tetrisBoard*/);
};

#endif