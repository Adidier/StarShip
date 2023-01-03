#include "Bullet.h"
#include "SystemManager.h"

namespace Game {

    Bullet::Bullet(System::Vector2 pos, System::Vector2 dir, float vel)
    {
        direction = dir;
        position = pos;
        velocity = vel;
    }

    Bullet::~Bullet()
    {
        delete sprite;
    }

    void Bullet::Init(std::string path)
    {
        sprite = new System::Image();
        sprite->LoadImage(path);
        size.x = sprite->GetWidth();
        size.y = sprite->GetHeight();
    }

    void Bullet::Draw()
    {
        auto sysManager = System::SystemManager::GetPtr();
        sysManager->Draw(sprite, position);
    }
    void Bullet::Update()
    {
        position = position + direction * velocity;
        auto sysManager = System::SystemManager::GetPtr();

        if (position.x < 0 || position.x > sysManager->GetScreenWidth())
        {
            IsActive(false);
        }

        if (position.y < 0 || position.y > sysManager->GetScreenHeight())
        {
            IsActive(false);
        }
    }

}