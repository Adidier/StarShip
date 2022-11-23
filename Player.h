#pragma once
#include "Image.h"
#include "SystemManager.h"
#include "Vector2.h"
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
	Vector2 position;
	float velocity;
	int energy;
	GunType gunType;
	int score;
	Image ship;
	SystemManager* sysManager;
public:
	void Init();
	void Init(float positionX, float positionY, float velocity, int energy);
	void Shoot();
	void Move();
	void Draw();
	void Update();
};

