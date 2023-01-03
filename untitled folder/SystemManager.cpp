#include "SystemManager.h"

namespace System {

	SystemManager* SystemManager::ptr = nullptr;

	SystemManager::SystemManager()
	{

	}

	SystemManager* SystemManager::GetPtr()
	{
		if (ptr == nullptr)
		{
			ptr = new SystemManager();
		}
		return ptr;
	}

	SDL_Renderer* SystemManager::GetRenderer()
	{
		return renderer;
	}

	bool SystemManager::InitWindow()
	{
		screenWidth = 640;
		screenHeight = 960;
		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			return false;
		}
		else
		{
			window = SDL_CreateWindow("Star Ship", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
		}
		if (window != nullptr)
		{
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		}
		return true;
	}

	int SystemManager::Input(std::map<char,bool> &keys)
	{
		SDL_Event e;
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
			{
				return 1;
			}
		}

		keys['w'] = keys['a'] = keys['s'] = keys['d'] = false;

		keys['r'] = keys['q'] = false;
		keys['j'] = false;

		const Uint8* keyboard = SDL_GetKeyboardState(NULL);
		if (keyboard[SDL_SCANCODE_W])
		{
			keys['w'] = true;
		}
		if (keyboard[SDL_SCANCODE_A])
		{
			keys['a'] = true;
		}
		if (keyboard[SDL_SCANCODE_S])
		{
			keys['s'] = true;
		}
		if (keyboard[SDL_SCANCODE_D])
		{
			keys['d'] = true;
		}

		if (keyboard[SDL_SCANCODE_ESCAPE])
		{
			keys['q'] = true;
		}
		if (keyboard[SDL_SCANCODE_SPACE])
		{
			keys['r'] = true;
		}

		if (keyboard[SDL_SCANCODE_J])
		{
			keys['j'] = true;
		}
		return 0;
	}

	void SystemManager::ClearScreen()
	{
		SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x0, 0xFF);
		SDL_RenderClear(renderer);
	}

	void SystemManager::RenderScreen()
	{
		SDL_RenderPresent(renderer);
	}

	void SystemManager::Draw(Image* img, Vector2 p)
	{
		SDL_Rect dst;
		dst.x = p.x;
		dst.y = p.y;
		dst.w = img->GetWidth();
		dst.h = img->GetHeight();

		SDL_RenderCopy(renderer, img->GetTexture(), NULL, &dst);
	}

	void SystemManager::Exit()
	{

	}

	int SystemManager::GetScreenWidth()
	{
		return screenWidth;
	}

	int SystemManager::GetScreenHeight()
	{
		return screenHeight;
	}
}