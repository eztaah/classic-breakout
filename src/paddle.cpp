#include "paddle.hpp"
#include <raylib.h>

Paddle::Paddle()
{
	width = 70;
	height = 10;
    x = (GetScreenWidth() / 2) - width / 2;
	y = GetScreenHeight() - 30;
    speed = 10;
}


void Paddle::Update()
{
    // move paddle
    if (IsKeyDown(KEY_D)) {
        x += 600 * GetFrameTime();
    };
    if (IsKeyDown(KEY_A)) {
        x -= 600 * GetFrameTime();
    };
}


void Paddle::Draw()
{
    DrawRectangle(x, y, width, height, BLUE);
}