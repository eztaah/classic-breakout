#pragma once 

class Paddle
{
    public:
        float height;
        float width;
        float x;
        float y;
        float speed;

        Paddle();
        void Update();
        void Draw();
};