#include <iostream>
#include <string>

#include "event.h"
#include "graphics.h"

using namespace std;

int main() {
	//Loads window and graphics
	Graphics * screen = new Graphics;
	//Board * tetrisBoard = new Board;

	while(1) {
		SDL_Delay(16);
		checkEvent();
		screen->updateScreen();
	}


}