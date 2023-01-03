#include "Enemy.h"
#include "Bullet.h"
#include "SystemManager.h"

namespace Game {

	Enemy::Enemy(std::list<GameObject*>* listEnemy)
	{
		this->listEnemy = listEnemy;
	}

	Enemy::~Enemy()
	{
		delete sprite;
	}

	void Enemy::Init(std::string path)
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

	void Enemy::Draw()
	{
		auto sysManager = System::SystemManager::GetPtr();
		sysManager->Draw(sprite, position);
	}

	void Enemy::Update()
	{
		auto sysManager = System::SystemManager::GetPtr();
		if (position.y < sysManager->GetScreenHeight() >> 1) {
			position.y = position.y +  0.1f;
		}
		else
		{
			position.x = position.x +0.1f * directionSide;
		}		
		if (rand() % 1000 < 2)
		{
			GameObject* bullet = new Bullet(position, System::Vector2(0, 1),0.4);
			bullet->Init("./Assets/bullet.png");
			listEnemy->push_back(bullet);
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

}