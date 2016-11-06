#include <iostream>
#include <string>


#include "graphics.h"

using namespace std;

bool running = true;
	

void close() {
	cout << "EXITING";
	running = false;
}

int main() {
	Graphics * testthis = new Graphics;


	atexit(close);
	while(running) {
		SDL_Delay(16);
		 SDL_Event event;

    /* Loop through waiting messages and process them */

    	while (SDL_PollEvent(&event)) {
        switch (event.type) {

            /* Closing the Window or pressing Escape will exit the program */
            case SDL_QUIT:
                exit(0);
            break;
        }
    }
		testthis->updateBoard();
	}


}