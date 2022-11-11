#include "GamePlayState.h"


void GamePlayState::Init()
{
	sysManager = SystemManager::GetPtr();
	sysManager->InitWindow();
	ship.LoadImage("./Assets/ship.png");
}

void GamePlayState::Input()
{
	sysManager->Input();
}

void GamePlayState::Update()
{

}

void GamePlayState::Draw()
{
	sysManager->ClearScreen();
	sysManager->Draw(&ship, 0, 0);
	sysManager->RenderScreen();
}