#include <iostream>
#include "SystemManager.h"
#include "GamePlayState.h"
#include "stdlib.h"
#include "time.h"

int main(int args, char* argc[])
{
	Game::GamePlayState game;
	game.Init();
	srand(time(NULL));
	while (true) //gameloop
	{
	   game.Input();
	   game.Update();
	   game.Draw();
	}
	return 0;
}