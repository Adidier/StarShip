#include "Enemy.h"
#include "SystemManager.h"

namespace Game {

	void Enemy::Init()
	{
		hits = 1;
		position.x = rand() % 550;
		position.y = 0;
		speed = 5;
		munitions = 10;
		sprite = new System::Image();
		sprite->LoadImage("./Assets/enemy.png");
		directionSide = 1;
		if (rand() % 100 > 50)
		{
			directionSide = -1;
		}
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
	}

	Vector2 Enemy::GetPosition()
	{
		return position;
	}
}