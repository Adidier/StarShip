#pragma once
#include "GameObject.h"
#include "Vector2.h"
#include "Image.h"

namespace Game {
    class Bullet :public GameObject
    {
    private:
        float velocity;
        System::Vector2 direction;
        System::Image* sprite;
    public:
        Bullet(System::Vector2 pos, System::Vector2 dir, float vel = 0.1);
        ~Bullet();
        void Init(std::string path);
        void Draw();
        void Update();
    };

}