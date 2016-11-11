#include <iostream>
#include <string>

#include "event.h"

using namespace std;

int main() {
	//Loads window and graphics
	Graphics * screen = new Graphics;
	Board * tetrisBoard = new Board;

	while(1) {
		int dropTimer = 0;
		//Change loop to determine how fast pieces drop
		while(dropTimer < 15) {
			SDL_Delay(50);
			checkEvent(tetrisBoard);
			checkClap(tetrisBoard);
			screen->updateScreen(tetrisBoard);
			++dropTimer;
		}
		tetrisBoard->dropPiece();
	}
}