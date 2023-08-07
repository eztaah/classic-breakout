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
    Game();
    void Update();
    void Draw();
    void Restart();
    bool running;

private:
    void CheckCollisionBallWall();
    void CheckCollisionBallPaddle();
    void CheckCollisionBallBrick();
    void InitBricks();
    void GameOver();

    Ball ball;
    Paddle paddle;
    Brick bricks[bricksPerLine*bricksPerColumns];

    unsigned int score;
    std::string scoreStr;
    unsigned int bestScore;
    std::string bestScoreStr;
};
