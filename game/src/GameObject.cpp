#include "GameObject.h"

namespace Game {

	System::Vector2 GameObject::GetPosition()
	{
		return position;
	}

	System::Vector2 GameObject::GetSize()
	{
		return size;
	}

	bool GameObject::IsActive()
	{
		return active;
	}

	void GameObject::IsActive(bool _active)
	{
		active = _active;
	}

	GameObject::~GameObject()
	{

	}
}