#pragma once
#include <raylib.hpp> 

class Brick
{
public:
    Brick();
    void Draw() const;

    Rectangle GetRectangle();
    void SetColor(Color _color);
    void SetXPosition(float x);
    void SetYPosition(float y);

private:
    Vector2 position;
    float height;
    float width;
    Color color;
};
