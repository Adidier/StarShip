#include "Player.h"

namespace Game {
	void Player::Init(std::string path)
	{
		position.x = 280;
		position.y = 840;
		velocity = 5;
		energy = 100;
		gunType = GunType::simple;
		score = 0;
		ship.LoadImage(path);
		sysManager = SystemManager::GetPtr();
		size.x = ship.GetWidth();
		size.y = ship.GetHeight();
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
		size.x = ship.GetWidth();
		size.y = ship.GetHeight();
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
			position.y = position.y - 0.06 * velocity;
		}
		else if (keys['s'])
		{
			position.y = position.y + 0.06 * velocity;
		}

		if (keys['a'])
		{
			position.x = position.x - 0.06 * velocity;
		}
		else if (keys['d'])
		{
			position.x = position.x + 0.06 * velocity;
		}

		if (keys['j'] && delayBullet == 0)
		{
			Bullet* bullet = new Bullet(position, System::Vector2(0, -1), 0.8);
			bullet->Init("./Assets/bulletPlayer.png");
			playerListBullets.push_back(bullet);
			delayBullet = 100;
		}

		if (delayBullet > 0) 
		{
			delayBullet--;
		}

	}

	void Player::Draw()
	{
		sysManager->Draw(&ship, position);

		for (auto bullet : playerListBullets)
		{
			bullet->Draw();
		}
	}

	void Player::Update()
	{
		for (auto bullet : playerListBullets)
		{
			bullet->Update();
		}
	}
}