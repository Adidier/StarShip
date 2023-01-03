#pragma once
#include "Vector2.h"
#include <string>

namespace Game {

    class GameObject
    {
    protected:
        System::Vector2 position;
        System::Vector2 size;
        bool active = true;
    public:
        ~GameObject();
        virtual void Init(std::string path) = 0;
        virtual void Draw() = 0;
        virtual void Update() = 0;
        System::Vector2 GetPosition();
        System::Vector2 GetSize();
        bool IsActive();
        void IsActive(bool _active);
    };

}