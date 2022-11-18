#include "Enemy.h"
#include "SystemManager.h"

namespace Game {

	void Enemy::Init()
	{
		hits = 1;
		positionX = rand() % 550;
		positionY = 0;
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
		sysManager->Draw(sprite, positionX, positionY);
	}

	void Enemy::Update()
	{
		auto sysManager = System::SystemManager::GetPtr();
		if (positionY < sysManager->GetScreenHeight() >> 1) {
			positionY += 0.1f;
		}
		else
		{
			positionX += 0.1f * directionSide;
		}		
	}

	float Enemy::GetPositionX()
	{
		return positionX;
	}

	float Enemy::GetPositionY()
	{
		return positionY;
	}
}