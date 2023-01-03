#pragma once

namespace System {

    class Vector2
    {
    public:
        float x;
        float y;
        //constructor con y sin parametros (0.5 final)
        //Eduardo :D
        Vector2();
        Vector2(int _x, int _y);
        //suma (0.5 final)
        //Jose
        Vector2 operator+(Vector2 a);
        //resta (0.5 final)
        //Daniela
        Vector2 operator-(Vector2 p);
        //producto punto (1 final)
        //eduardo intento (1
        float operator*(Vector2 p);
        //producto escalar (0.5 final)
        //Alessandro (0.5)
        //eduardo (0.5)
        Vector2 operator*(float a);
    };

}