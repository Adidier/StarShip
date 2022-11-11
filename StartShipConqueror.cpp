#include <iostream>
#include "SystemManager.h"
#include "GamePlayState.h"

int main(int args, char* argc[])
{
	GamePlayState game;
	game.Init();

	while (true) //gameloop
	{
	   game.Input();
	   game.Update();
	   game.Draw();
	}
	return 0;
}