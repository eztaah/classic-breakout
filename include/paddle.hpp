#pragma once 

class Paddle
{
public:
    Paddle();
    void Update();
    void Draw();

    // Encapsulation
    Rectangle GetRectangle();
    Vector2 GetSpeed();
    void SetXPosition(float x);
    void SetYPosition(float y);
    void SetXSpeed(float x);
    void SetYSpeed(float y);

private:
    Vector2 position;
    float speed;
    float width;
    float height;
};