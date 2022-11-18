#pragma once
#include "Image.h"
#include "Enemy.h"
#include "Player.h"
#include "SystemManager.h"
#include <list>

namespace Game {
	class GamePlayState
	{
	private:
		Player player1;
		std::list<Enemy*> listEnemy;
		System::SystemManager* sysManager;
	public:
		void Init();
		void Update();
		void Draw();
		void Input();
	};
};

