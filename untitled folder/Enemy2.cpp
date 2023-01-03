#include "Enemy2.h"
#include "SystemManager.h"
#include "Bullet.h"

namespace Game {

	Enemy2::Enemy2(std::list<GameObject*>* listEnemy)
	{
		this->listEnemy = listEnemy;
	}

	Enemy2::~Enemy2()
	{
		delete sprite;
	}

	void Enemy2::Init(std::string path)
	{
		hits = 1;
		position.x = rand() % 550;
		position.y = 0;
		speed = 5;
		munitions = 10;
		sprite = new System::Image();
		sprite->LoadImage(path);
		directionSide = 1;
		if (rand() % 100 > 50)
		{
			directionSide = -1;
		}
		size.x = sprite->GetWidth();
		size.y = sprite->GetHeight();
	}

	void Enemy2::Draw()
	{
		auto sysManager = System::SystemManager::GetPtr();
		sysManager->Draw(sprite, position);
	}

	void Enemy2::Update()
	{
		auto sysManager = System::SystemManager::GetPtr();
		position.y = position.y + 0.1f;

		//if (position.x > 0 && position.x < 400)
		{
			position.x = position.x + 0.1 * directionSide;
			if (position.x < 0)
				directionSide = 1;
			else if (position.x > 550)
				directionSide = -1;
		}


		if (rand() % 1000 < 2)
		{
			GenerateBullet(System::Vector2(1,1));
			GenerateBullet(System::Vector2(0, 1));
			GenerateBullet(System::Vector2(-1, 1));

			GenerateBullet(System::Vector2(1, -1));
			GenerateBullet(System::Vector2(0, -1));
			GenerateBullet(System::Vector2(-1, -1));

			GenerateBullet(System::Vector2(1, 0));
			GenerateBullet(System::Vector2(-1, 0));
		}
		if (position.x < 0 || position.x > sysManager->GetScreenWidth())
		{
			IsActive(false);
		}

		if (position.y < 0 || position.y > sysManager->GetScreenHeight())
		{
			IsActive(false);
		}
	}
	void Enemy2::GenerateBullet(System::Vector2 dir)
	{
		GameObject* bullet = new Bullet(position, dir, 0.4);
		bullet->Init("./Assets/bullet.png");
		listEnemy->push_back(bullet);
	}
}