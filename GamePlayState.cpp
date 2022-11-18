#include "GamePlayState.h"
namespace Game {
	void GamePlayState::Init()
	{
		sysManager = System::SystemManager::GetPtr();
		sysManager->InitWindow();
		player1.Init();		
	}

	void GamePlayState::Input()
	{
		player1.Move();
	}

	void GamePlayState::Update()
	{
		if (rand() % 1500 < 2) {
			auto enemy = new Enemy();
			enemy->Init();
			listEnemy.push_back(enemy);
		}
		for (auto enemy : listEnemy) {
			enemy->Update();
		}
	}

	void GamePlayState::Draw()
	{
		sysManager->ClearScreen();
		player1.Draw();
		for (auto enemy : listEnemy) {
			enemy->Draw();
		}
		sysManager->RenderScreen();
	}
}