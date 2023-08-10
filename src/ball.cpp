#include "ball.hpp"
#include <raylib.hpp>


Ball::Ball()
{
    position = {GetScreenWidth() / 3.0f, GetScreenHeight() / 2.0f};
    speed = {30.0f, 400.0f};
	width = 7.0f;
	height = 7.0f;
}


void Ball::Update()
{
    position.x += speed.x * GetFrameTime();
    position.y += speed.y * GetFrameTime();
}


void Ball::Draw() const
{
    DrawRectangle(position.x, position.y, width, height, WHITE);
}


Rectangle Ball::GetRectangle() 
{
    return {position.x, position.y, width, height};
}


Vector2 Ball::GetSpeed() 
{
    return speed;
}


void Ball::SetXPosition(float x) 
{
    position.x = x;
}


void Ball::SetYPosition(float y) 
{
    position.y = y;
}


void Ball::SetXSpeed(float x) 
{
    speed.x = x;
}


void Ball::SetYSpeed(float y) 
{
    speed.y = y;
}
