#include "SystemManager.h"

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
	screenHeight = 480;
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

int SystemManager::Input()
{
	SDL_Event e;
	while (SDL_PollEvent(&e))
	{
		if (e.type == SDL_QUIT)
		{
			return 1;
		}
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

void SystemManager::Draw(Image* img, int x, int y)
{
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	dst.w = img->GetWidth();
	dst.h = img->GetHeight();

	SDL_RenderCopy(renderer, img->GetTexture(), NULL, &dst);
}

void SystemManager::Exit()
{

}