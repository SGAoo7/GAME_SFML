#include "Header Files/Game.h"

int main()
{
	Game game;

	while (!game.GetWindow()->isDone) {
		game.Render();
		game.HandleInput();
		game.Update();
	}

	return 0;
}