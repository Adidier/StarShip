#pragma once
#include "Image.h"
#include "Vector2.h"
#include "GameObject.h"
#include <list>

namespace Game {
    class Enemy : public GameObject
    {
    private:
        int hits;
        int speed;
        int munitions;
        int directionSide;
        System::Image* sprite;
        std::list<GameObject*>* listEnemy;
    public:
        Enemy(std::list<GameObject*>* listEnemy);
        ~Enemy();
        void Init(std::string path);
        void Draw();
        void Update();
    };
}

