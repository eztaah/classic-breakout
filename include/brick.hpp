#pragma once 

class Brick
{
    public:
        float x;
        float y;
        float height;
        float width;
    
        Brick();
        void Draw(unsigned int iterator);
};
