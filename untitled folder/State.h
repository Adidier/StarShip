#pragma once
#include "SystemManager.h"

namespace Game 
{
	class State
	{
	protected:
		System::SystemManager* sysManager;
	public:
		virtual void Init() = 0;
		virtual void Input() = 0;
		virtual void Update() = 0;
		virtual void Draw() = 0;
	};
};