#pragma once
#include "Image.h"
#include "Enemy.h"
#include "SystemManager.h"
#include <list>

namespace Game {
	class GamePlayState
	{
	private:
		System::Image ship;
		std::list<Game::Enemy*> listEnemy;
		System::SystemManager* sysManager;
	public:
		void Init();
		void Update();
		void Draw();
		void Input();
	};
};

