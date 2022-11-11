#pragma once
#include "SDL.h"
#include "Image.h"

class SystemManager
{
public:
	bool InitWindow();
	int Input();

	void ClearScreen();
	void Draw(Image* img, int x, int y);
	void Exit();
	static SystemManager* GetPtr();
	SDL_Renderer* GetRenderer();
private:
	int screenWidth;
	int screenHeight;
	bool fullScreen;
	SystemManager();
	static SystemManager* ptr;
	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;
};

