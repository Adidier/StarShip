#include <iostream>
#include "SystemManager.h"
#include "GamePlayState.h"
#include "MenuState.h"
#include "State.h"
#include "stdlib.h"
#include "time.h"
#include <stack>

using namespace Game;

int main(int args, char* argc[])
{
	auto sysManager = System::SystemManager::GetPtr();
	sysManager->InitWindow();
	std::stack<Game::State*> gamestates;
	State *menu = new MenuState(&gamestates);
	gamestates.push(menu);
	menu->Init();
	srand(time(NULL));
	while (true)
	{
		if (gamestates.size() == 0)
			break;
		auto gameStateTop = gamestates.top();
		if (gameStateTop)
		{
			gameStateTop->Input();
			gameStateTop->Update();
			sysManager->ClearScreen();
			gameStateTop->Draw();
			sysManager->RenderScreen();
		}
	}
	return 0;
}

