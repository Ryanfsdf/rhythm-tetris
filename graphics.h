#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#include "SDL2/SDL2_gfxPrimitives.h"

class Graphics {
private:
	SDL_Window *window;
	SDL_Renderer *render;
	SDL_Texture *display;
public:
	Graphics();
	~Graphics();

	void updateBoard();
	void closeBoard();
};