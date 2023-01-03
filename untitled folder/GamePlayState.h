#pragma once
#include "Image.h"
#include "GameObject.h"
#include "Player.h"
#include "SystemManager.h"
#include "Bullet.h"
#include "State.h"
#include <list>
#include <stack>

namespace Game {
	class GamePlayState : public State
	{
	private:
		Player player1;
		std::list<GameObject*> listEnemy;
		std::stack<Game::State*>* stackstates;
		bool stopGenerate = false;
	public:
		GamePlayState(std::stack<Game::State*>* states);
		void Init() override;
		void Update() override;
		void DeleteInactiveGameObjects();
		bool CheckCollision( Game::GameObject* enemy);
		bool CheckCollisionPlayerBullets(Game::GameObject* enemy, Game::GameObject* bullet);
		void Draw() override;
		void Input() ;
	};
};

