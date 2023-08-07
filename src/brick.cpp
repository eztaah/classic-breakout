#include "brick.hpp"
#include <raylib.hpp>
#include <iostream>


Brick::Brick()
{
	width = 38.0f;
	height = 11.0f;
}

void Brick::Draw(unsigned int iterator)
{
	if(iterator < 30) { DrawRectangle(x, y, width, height, RED); }
	else if((iterator >= 30) && ((iterator < 60))) { DrawRectangle(x, y, width, height, ORANGE); }
	else if((iterator >= 60) && ((iterator < 90))) { DrawRectangle(x, y, width, height, GREEN); }
	else if((iterator >= 90) && ((iterator < 120))) { DrawRectangle(x, y, width, height, YELLOW); }
	else { throw std::exception(); }

}