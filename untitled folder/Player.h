#pragma once
#include "GameObject.h"
#include "Image.h"
#include "SystemManager.h"
#include "Vector2.h"
#include <list>
#include <string>
#include "Bullet.h"

using namespace System;

namespace Game {
	enum GunType
	{
		simple,
		doble,
		mega
	};

	class Player : public GameObject
	{
	private:
		float velocity;
		int energy;
		GunType gunType;
		int score;
		Image ship;
		SystemManager* sysManager;
		int delayBullet = 0;
	public:
		void Init(std::string path);
		void Init(float positionX, float positionY, float velocity, int energy);
		void Shoot();
		void Move();
		void Draw();
		void Update();
		std::list<Bullet*> playerListBullets;
	};

}