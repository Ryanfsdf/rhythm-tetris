#include "graphics.h"

void checkEvent() {
	SDL_Event event;

	while (SDL_PollEvent(&event)) {
		switch (event.type) {

			//Detect window close
		    case SDL_QUIT:
		        exit(0);
		    break;
		}
	}
}
