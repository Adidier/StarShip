#include "MenuState.h"
#include "GamePlayState.h"

namespace Game
{
	MenuState::MenuState(std::stack<Game::State*>* states)
	{
		stackstates = states;
	}

	void MenuState::Input()
	{
		std::map<char, bool> keys;
		sysManager->Input(keys);

		if (keys['r'])
		{
			Game::State* game = new Game::GamePlayState(stackstates);
			game->Init();
			stackstates->push(game);
		}
		if (keys['q'])
		{
			stackstates->pop();
		}
	}

	void MenuState::Init()
	{
		background = new System::Image();
		background->LoadImage("./Assets/menu.png");

		ship = new System::Image();
		ship->LoadImage("./Assets/shipMenu.png");
		sysManager = System::SystemManager::GetPtr();
	}

	void MenuState::Update()
	{

	}

	void MenuState::Draw()
	{
		sysManager->Draw(background, System::Vector2(0, 0));
		sysManager->Draw(ship, System::Vector2(x, 300));
		x = x + 0.1;
		if (x > sysManager->GetScreenWidth())
		{
			x = -250;
		}
	}
}