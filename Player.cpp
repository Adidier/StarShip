#include "Player.h"

void Player::Init()
{
	positionX = 280;
	positionY = 840;
	velocity = 5;
	energy = 100;
	gunType = GunType::simple;
	score = 0;
	ship.LoadImage("./Assets/ship.png");
	sysManager = SystemManager::GetPtr();
}

void Player::Shoot()
{

}

void Player::Move()
{
	std::map<char, bool> keys;
	sysManager->Input(keys);

	if (keys['w'])
	{
		positionY = positionY - 0.1*velocity;
	}
	else if (keys['s'])
	{
		positionY = positionY + 0.1 * velocity;
	}

	if (keys['a'])
	{
		positionX = positionX - 0.1 * velocity;
	}
	else if (keys['d'])
	{
		positionX = positionX + 0.1 * velocity;
	}
}

void Player::Draw()
{
	sysManager->Draw(&ship, positionX, positionY);
}

void Player::Update()
{

}