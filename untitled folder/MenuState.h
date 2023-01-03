#pragma once
#include "State.h"
#include "Image.h"
#include <stack>

namespace Game 
{
	class MenuState : public State
	{
	private:
		System::Image* background;
		System::Image* ship;
		float x = -250;
		std::stack<Game::State*>* stackstates;
	public:
		MenuState(std::stack<Game::State*>* states);
		void Init() override;
		void Update() override;
		void Draw() override;
		void Input();
	};
}

