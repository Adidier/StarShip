#pragma once
#include "Image.h"
#include "SystemManager.h"

class GamePlayState
{
private:
	Image ship;
	SystemManager* sysManager;
public:
	void Init();
	void Update();
	void Draw();
	void Input();
};

