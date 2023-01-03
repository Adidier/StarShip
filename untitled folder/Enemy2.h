#pragma once
#include "image.h"
#include "Vector2.h"
#include "GameObject.h"
#include <list>

namespace Game 
{
    class Enemy2 : public GameObject
    {
    private:
        int hits;
        int speed;
        int munitions;
        int directionSide;
        System::Image* sprite;
        std::list<GameObject*>* listEnemy;
    public:
        Enemy2(std::list<GameObject*>* listEnemy);
        ~Enemy2();
        void Init(std::string path);
        void Draw();
        void Update();
        void GenerateBullet(System::Vector2 dir);
    };
}

