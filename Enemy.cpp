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
	}

	void Enemy::Draw()
	{
		auto sysManager = System::SystemManager::GetPtr();
		sysManager->Draw(sprite, positionX, positionY);
	}

	void Enemy::Update()
	{
		positionY += 0.1f;
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