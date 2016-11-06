#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#include "SDL2/SDL2_gfxPrimitives.h"

class Graphics {
private:
	SDL_Window *window;
	SDL_Renderer *render;
public:
	Graphics();
	~Graphics();

	void updateScreen();
	void closeScreen();
};