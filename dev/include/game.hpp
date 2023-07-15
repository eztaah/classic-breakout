#pragma once

#include "ball.hpp"
#include "paddle.hpp"
#include "brick.hpp"
#include <string>

const unsigned int bricksPerLine{15};
const unsigned int bricksPerColumns{6};

const unsigned int xGapBetweenBricks{8};
const unsigned int yGapBetweenBricks{5};

class Game
{
    public:
        Ball ball = Ball();
        Paddle paddle = Paddle();
        Brick bricks[bricksPerLine*bricksPerColumns];

        bool running{true};

        unsigned int score{0};
        std::string scoreStr{"0"};

        unsigned int bestScore;
        std::string bestScoreStr{""};

        Game();
        void InitBricks();
        void Draw();
        void Update();

        void CheckCollisionBallWall();
        void CheckCollisionBallPaddle();
        void CheckCollisionBallBrick();

        void GameOver();
        void Restart();
};
