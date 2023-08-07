#include "ball.hpp"
#include <raylib.h>


Ball::Ball()
{
    x = GetScreenWidth() / 3;
	y = GetScreenHeight() / 2;
	speedX = 100;
	speedY = 400;
	width = 7;
	height = 7;
}


void Ball::Update()
{
    // position
    x += speedX * GetFrameTime();
    y += speedY * GetFrameTime();
}


void Ball::Draw()
{
    DrawRectangle(x, y, width, height, WHITE);
}