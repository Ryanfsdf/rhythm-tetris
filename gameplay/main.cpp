#include <iostream>
#include <string>

#include "event.h"

using namespace std;

int main() {
	//Loads window and graphics
	Graphics * screen = new Graphics;
	Board * tetrisBoard = new Board;

	bool isClapEnabled = true;
	bool isLoudFasterEnabled = true;

	while(1) {
		int dropLoop = 0;
		int dropTimer = 15;

		//Change dropTimer to determine how fast pieces drop
		while(dropLoop < dropTimer) {
			SDL_Delay(50);
			checkEvent(tetrisBoard);
			if (isClapEnabled) {
				checkClap(tetrisBoard);
			}
			if (isLoudFasterEnabled) {
				dropTimer = 15 - getLoudness(tetrisBoard)/10;
			}
			screen->updateScreen(tetrisBoard);
			++dropLoop;
		}
		tetrisBoard->dropPiece();
	}
}