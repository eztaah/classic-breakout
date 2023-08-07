#pragma once 

class Ball
{
    public:
        float x;
        float y;
        float speedX;
        float speedY;
        float height;
        float width;
    
        Ball();
        void Update();
        void Draw();
};
