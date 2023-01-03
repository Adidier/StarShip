#include "GamePlayState.h"
#include "Enemy.h"
#include "Enemy2.h"
#include <iostream>
#include <vector>

namespace Game {

	GamePlayState::GamePlayState(std::stack<Game::State*>* states)
	{
		stackstates = states;
	}

	void GamePlayState::Init()
	{
		player1.Init("./Assets/ship.png");
	}

	void GamePlayState::Input()
	{
		player1.Move();
	}

	void GamePlayState::Update()
	{
		DeleteInactiveGameObjects();

		if (rand() % 1500 < 2) 
		{
			GameObject* enemy;
			if (rand() % 100 < 50)
			{
				enemy = new Enemy(&listEnemy);
			}
			else
			{
				enemy = new Enemy2(&listEnemy);
			}
			enemy->Init("./Assets/enemy.png");
			listEnemy.push_back(enemy);
		}
		for (auto enemy : listEnemy) 
		{
			enemy->Update();
		}

		for (auto enemy : listEnemy)
		{
			if (CheckCollision(enemy))
			{
				stackstates->pop();
			}
		}

		for (auto bullet : player1.playerListBullets)
		{
			for (auto enemy : listEnemy)
			{
				auto enemy1 = dynamic_cast<Enemy*>(enemy);
				auto enemy2 = dynamic_cast<Enemy2*>(enemy);

				if (CheckCollisionPlayerBullets(enemy, bullet) && (enemy1|| enemy2))
				{
					std::cout << "enemigo alcanzado";
					enemy->IsActive(false);
					bullet->IsActive(false);
				}
			}
		}

		player1.Update();
	}

	void GamePlayState::DeleteInactiveGameObjects()
	{
		std::vector<GameObject*> objectsToClean;
		for (auto enemy : listEnemy)
		{
			if (!enemy->IsActive())
			{
				objectsToClean.push_back(enemy);
			}
		}
		for (auto enemyToClean : objectsToClean)
		{
			listEnemy.remove(enemyToClean);

			Enemy* enemy = dynamic_cast<Enemy*>(enemyToClean);
			if (enemy != nullptr)
			{
				delete enemy;
				continue;
			}
			Enemy2* enemy2 = dynamic_cast<Enemy2*>(enemyToClean);
			if (enemy2) {
				delete enemy2;
				continue;
			}
			Bullet* bullet = dynamic_cast<Bullet*>(enemyToClean);
			if (bullet) {
				delete bullet;
				continue;
			}
		}


		std::vector<Bullet*> objectsToClean2;
		for (auto bullet : player1.playerListBullets)
		{
			if (!bullet->IsActive())
			{
				objectsToClean2.push_back(bullet);
			}
		}
		for (auto bulletToClean : objectsToClean2)
		{
			player1.playerListBullets.remove(bulletToClean);

			Bullet* bullet = dynamic_cast<Bullet*>(bulletToClean);
			if (bullet != nullptr)
			{
				delete bullet;
				continue;
			}
		}
	}

	bool GamePlayState::CheckCollisionPlayerBullets(Game::GameObject* enemy, Game::GameObject* bullet)
	{
		System::Vector2 enemyPos = enemy->GetPosition();

		System::Vector2 enemySize = enemy->GetSize();

		System::Vector2 playerPos = bullet->GetPosition();

		System::Vector2 playerSize = bullet->GetSize();

		if (enemyPos.x < playerPos.x + playerSize.x &&
			enemyPos.x + enemySize.x > playerPos.x &&
			enemyPos.y < playerPos.y + playerSize.y &&
			enemySize.y + enemyPos.y > playerPos.y)
		{
			return true;
		}

		return false;
	}

	bool GamePlayState::CheckCollision( Game::GameObject* enemy)
	{
		System::Vector2 enemyPos = enemy->GetPosition();

		System::Vector2 enemySize = enemy->GetSize();

		System::Vector2 playerPos = player1.GetPosition();

		System::Vector2 playerSize = player1.GetSize();

		if (enemyPos.x < playerPos.x + playerSize.x &&
			enemyPos.x + enemySize.x > playerPos.x &&
			enemyPos.y < playerPos.y + playerSize.y &&
			enemySize.y + enemyPos.y > playerPos.y) 
		{
			return true;
		}
			
		return false;
	}

	void GamePlayState::Draw()
	{
		player1.Draw();
		for (auto enemy : listEnemy) {
			enemy->Draw();
		}
	}
}