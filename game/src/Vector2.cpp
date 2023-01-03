#include "Vector2.h"

namespace System {

    Vector2::Vector2() {
        x = 0;
        y = 0;
    }

    Vector2::Vector2(int _x, int _y) {
        x = _x;
        y = _y;
    }
    //punto para todos pendiente (espera clase)
    //suma (0.5 final)
    //Jose
    Vector2 Vector2::operator+(Vector2 a) {
        Vector2 result;
        result.x = x + a.x;
        result.y = y + a.y;
        return result;
    }
    //resta (0.5 final)
    //Daniela
    Vector2 Vector2::operator-(Vector2 p) {
        Vector2 result;
        result.x = x - p.x;
        result.y = y - p.y;
        return result;
    }
    //producto punto (1 final)
    //eduardo intento (1 final)
    float Vector2::operator*(Vector2 p) {
        float result;
        result = (x * p.x) + (y * p.y);
        return result;
    }

    //producto escalar (0.5 final)
    //Alessandro (0.5)
    //eduardo (0.5)
    Vector2 Vector2::operator*(float a) {
        Vector2 result;
        result.x = x * a;
        result.y = y * a;
        return result;
    }
}