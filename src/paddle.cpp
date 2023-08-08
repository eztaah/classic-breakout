#include "paddle.hpp"
#include <raylib.hpp>


Paddle::Paddle()
{
    position = {(GetScreenWidth() / 2.0f) - width / 2.0f, GetScreenHeight() - 30.0f};
    speed = 10.0f;
	width = 70.0f;
	height = 10.0f;
}


void Paddle::Update()
{
    if (IsKeyDown(KEY_D)) {
        position.x += 600.0f * GetFrameTime();
    };
    if (IsKeyDown(KEY_A)) {
        position.x -= 600.0f * GetFrameTime();
    };
}


void Paddle::Draw()
{
    DrawRectangle(position.x, position.y, width, height, BLUE);
}


// Encapsulation
Rectangle Paddle::GetRectangle() { return {position.x, position.y, width, height}; }

void Paddle::SetXPosition(float x) { position.x = x; }

void Paddle::SetYPosition(float y) { position.y = y; }