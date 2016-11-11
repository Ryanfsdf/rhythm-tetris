#include <iostream>
#include <string>

#include "event.h"
#include "graphics.h"

using namespace std;

int main() {
	//Loads window and graphics
	int hi;
	std::cin >> hi;
	Graphics * screen = new Graphics;
	Board * tetrisBoard = new Board;

	while(1) {
		int loop = 0;
		//Change loop to determine how fast pieces drop
		while(loop < 15) {
			SDL_Delay(50);
			checkEvent(tetrisBoard);
			screen->updateScreen(tetrisBoard);
			++loop;
		}
		tetrisBoard->dropPiece();
	}
}