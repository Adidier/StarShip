#pragma once
#include "Image.h"
#include "SystemManager.h"

using namespace System;

enum GunType
{
	simple,
	doble,
	mega
};

class Player
{
private:
	float positionX;
	float positionY;
	float velocity;
	int energy;
	GunType gunType;
	int score;
	Image ship;
	SystemManager* sysManager;
public:
	void Init();
	void Shoot();
	void Move();
	void Draw();
	void Update();
};

