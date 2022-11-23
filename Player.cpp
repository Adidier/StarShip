#include "Player.h"

void Player::Init()
{
	position.x = 280;
	position.y = 840;
	velocity = 5;
	energy = 100;
	gunType = GunType::simple;
	score = 0;
	ship.LoadImage("./Assets/ship.png");
	sysManager = SystemManager::GetPtr();
}
void Player::Init(float _positionX, float _positionY, 
				float _velocity, int energy)
{
	position.x = _positionX;
	position.y = _positionY;
	velocity = _velocity;
	this->energy = energy;
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
		position.y = position.y - 0.1*velocity;
	}
	else if (keys['s'])
	{
		position.y = position.y + 0.1 * velocity;
	}

	if (keys['a'])
	{
		position.x = position.x - 0.1 * velocity;
	}
	else if (keys['d'])
	{
		position.x = position.x + 0.1 * velocity;
	}
}

void Player::Draw()
{
	sysManager->Draw(&ship, position);
}

void Player::Update()
{

}