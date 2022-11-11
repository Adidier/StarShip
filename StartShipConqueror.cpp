#include <iostream>
#include "SystemManager.h"

void Update()
{
}

void Draw()
{
}

int main(int args, char* argc[])
{
	bool exit = false;
	SystemManager* sysManager = SystemManager::GetPtr();
	sysManager->InitWindow();
	while (exit == false) //gameloop
	{
       exit = sysManager->Input();
	   Update();
	   Draw();		
	}
	return 0;
}