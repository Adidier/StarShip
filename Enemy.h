#pragma once
#include "image.h"
#include "Vector2.h"
namespace Game {
    class Enemy
    {
    private:
        int hits;
        Vector2 position;
        int speed;
        int munitions;
        int directionSide;
        System::Image* sprite;
    public:
        void Init();
        void Draw();
        void Update();
        Vector2 GetPosition();
    };
}

