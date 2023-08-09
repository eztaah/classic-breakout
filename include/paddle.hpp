#pragma once 
#include <raylib.hpp>

class Paddle
{
public:
    Paddle();
    void Update();
    void Draw();

    Rectangle GetRectangle();
    void SetXPosition(float x);
    void SetYPosition(float y);

private:
    Vector2 position;
    float speed;
    float width;
    float height;
};