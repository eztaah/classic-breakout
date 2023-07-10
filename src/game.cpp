#include <raylib.h>
#include <string>
#include <fstream>
#include <iostream>
#include "../include/ball.hpp"
#include "../include/paddle.hpp"
#include "../include/game.hpp"
#include "../include/library.hpp"
#include "../include/brick.hpp"



Game::Game()
{
    InitBricks();

    // get the best score
    std::ifstream fichier{"user/best_score.txt"}; 
    fichier >> bestScoreStr;
    bestScore = std::stoi(bestScoreStr);
    fichier.close();
}


// MAIN
void Game::Draw()
{
    // Draw paddle
    paddle.Draw();

    // draw score & best score
    DrawText(scoreStr.c_str(), 330, 30, 30, WHITE);
    DrawText(("Best score : " + bestScoreStr).c_str(), 10, 30, 20, RED);

    // Draw bricks
    for (unsigned int k{0}; k < bricksPerLine*bricksPerColumns; ++k) { bricks[k].Draw(k); };

    if(running) {
        // Draw ball
        ball.Draw();
    } else {
        // Draw text
        DrawText("game over", 200, 350, 60, YELLOW);
        DrawText("press space to restart", 200, 430, 20, YELLOW);
    }
}

void Game::Update()
{
    if(running) {
        ball.Update();
        paddle.Update();
        CheckCollisionBallWall();
        CheckCollisionBallPaddle();
        CheckCollisionBallBrick();
    };
}


// OTHER
void Game::InitBricks()
{
    unsigned int n = 0;
	for (unsigned int j{0}; j < bricksPerColumns; ++j) 
	{
		for (unsigned int i{0}; i < bricksPerLine; ++i) 
		{
			bricks[n].x = 10 + i * (bricks[n].width + xGapBetweenBricks);
			bricks[n].y = 120 + j * (bricks[n].height + yGapBetweenBricks);
			++n;
		};
	};
}

void Game::GameOver()
{
    running = false;
    if(score > bestScore) {
        // convert score to string
        scoreStr = std::to_string(score);
        
        // open file
        std::ofstream fichier{"user/best_score.txt"};
        if(fichier.is_open()) {
            fichier << score;
        }
    }
}

void Game::Restart() 
{
    // Reset ball, paddle and score
    ball.x = GetScreenWidth() / 2;
	ball.y = GetScreenHeight() / 2;
    paddle.x = (GetScreenWidth() / 2) - paddle.width / 2;
    score = 0;
    scoreStr = "0";

    //reset bricks
	for (unsigned int n{0}; n < bricksPerColumns*bricksPerLine; ++n) 
	{
        if((bricks[n].x >= 2000))
        {
            bricks[n].x -= 2000;
        }
	};

    // get the best score
    std::ifstream fichier{"user/best_score.txt"}; 
    fichier >> bestScoreStr;
    bestScore = std::stoi(bestScoreStr);
    fichier.close();

    running = true;
}


// COLLISIONS
void Game::CheckCollisionBallWall()
{
    // wall collisions
    if (ball.x < 0) {
        ball.x = 0;
        ball.speedX *= -1;
    } else if (ball.x > GetScreenWidth() - ball.width) {
        ball.x = GetScreenWidth() - ball.width;
        ball.speedX *= -1;
    };
    if (ball.y < 0) {
        ball.y = 0;
        ball.speedY *= -1;
    }
    else if (ball.y > GetScreenHeight() - ball.height) {
        GameOver();
    };
}

void Game::CheckCollisionBallPaddle()
{
    if (CheckCollisionRecs(Rectangle{ball.x, ball.y, ball.width, ball.height}, Rectangle{paddle.x, paddle.y, paddle.width, paddle.height}))
    {
        if (ball.speedY > 0) //prevent the ball from boncing inside the paddle
        {
            ball.speedY *= -1;
            if (ball.x - paddle.x < paddle.width/2) {
                ball.speedX = -10 * myUtils::abs(ball.x - paddle.x - paddle.width/2) ;
            }
            else {
                ball.speedX = 10 * myUtils::abs(ball.x - paddle.x - paddle.width/2);
            }
        };
    };
}

void Game::CheckCollisionBallBrick()
{
    for (unsigned int k{0}; k < bricksPerLine*bricksPerColumns; ++k)
    {
        if (CheckCollisionRecs(Rectangle{ball.x, ball.y, ball.width, ball.height }, Rectangle{bricks[k].x - xGapBetweenBricks/2, bricks[k].y- yGapBetweenBricks/2, bricks[k].width + xGapBetweenBricks/2, bricks[k].height + yGapBetweenBricks/2}))
        {
            ball.speedY *= -1;
            bricks[k].x += 2000;
            ++score;
            scoreStr = std::to_string(score);
        }
    };
}