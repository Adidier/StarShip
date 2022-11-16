#include "GamePlayState.h"
namespace Game {
	void GamePlayState::Init()
	{
		sysManager = System::SystemManager::GetPtr();
		sysManager->InitWindow();
		ship.LoadImage("./Assets/ship.png");


	}

	void GamePlayState::Input()
	{
		sysManager->Input();
	}

	void GamePlayState::Update()
	{
		if (rand() % 500 < 2) {
			auto enemy = new Enemy();
			enemy->Init();
			listEnemy.push_back(enemy);
		}
		for (auto enemy : listEnemy) {
			enemy->Update();
		}
		//enemy1.Update();
	}

	void GamePlayState::Draw()
	{
		sysManager->ClearScreen();
		sysManager->Draw(&ship, 0, 0);
		for (auto enemy : listEnemy) {
			enemy->Draw();
		}
		sysManager->RenderScreen();
	}
}