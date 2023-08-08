#pragma once
#include "ball.hpp"
#include "paddle.hpp"
#include "brick.hpp"
#include <string>


const unsigned int numberOfColumns {15};
const unsigned int numberOfLines {6};

const unsigned int xGapBetweenBricks {8};
const unsigned int yGapBetweenBricks {5};


class Game
{
public:
    Game();
    void Update();
    void Draw();
    void Restart();
    bool running;

private:
    void DrawScore();
    std::string GetBestScore();
    void SetupBestScoreFile();
    void InitBricks();
    void GameOver();

    void ManageCollisionBallWall();
    void ManageCollisionBallPaddle();
    void ManageCollisionBallBrick();

    Ball ball;
    Paddle paddle;
    Brick bricks[numberOfLines * numberOfColumns];

    int unsigned score;
    std::string bestScoreStr;
};
