#pragma once
class Vector2
{
public:
	float x;
	float y;
	//constructor con y sin parametros (0.5 final)
    //Eduardo :D
    Vector2(){
        x=0;
        y=0;
    }
    Vector2(int _x ,int _y){
        x=_x;
        y=_y;
    }

	//suma (0.5 final)
    //Jose
    Vector2 operator+(Vector2 a) {
	//resta (0.5 final)
    //Daniela
    Vector2 operator-(Vector2 p) {
	//producto punto (1 final)
    //eduardo intento (1
    float operator*(Vector2 p){
        float result;
        result= (x*p.x)+(y*p.y);
        return result;
    }

	//producto escalar (0.5 final)
    //Alessandro (0.5)
    //eduardo (0.5)
    Vector2 operator*(float a){
        Vector2 result;
        result.x=x*a;
        result.y=y*a;
        return result;
    }
};
