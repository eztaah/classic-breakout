#pragma once 

class Ball
{
    public:
        float x;
        float y;
        float speedX;
        float speedY;
        int height;
        int width;
    
        Ball();
        void Update();
        void Draw();
};
