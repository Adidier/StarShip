#pragma once
#include "image.h"

namespace Game {
    class Enemy
    {
    private:
        int hits;
        float positionX;
        float positionY;
        int speed;
        int munitions;
        int directionSide;
        System::Image* sprite;
    public:
        void Init();
        void Draw();
        void Update();
        float GetPositionX();
        float GetPositionY();
    };
}

