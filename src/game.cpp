#include "game.hpp"
#include "ball.hpp"
#include "paddle.hpp"
#include "library.hpp"
#include "brick.hpp"
#include <raylib.hpp>
#include <string>
#include <fstream>
#include <iostream>
#include <cmath>


Game::Game()
{
    ball = Ball();
    paddle = Paddle();

    score = 0;
    bestScore = GetBestScore();
    InitBricks();
    running = true;
}


void Game::Update()
{
    if(running) 
    {
        ManageCollisionBallWall();
        ManageCollisionBallPaddle();
        ManageCollisionBallBrick();
        ball.Update();
        paddle.Update();
    } else 
    {
        if (IsKeyDown(KEY_SPACE)) {
            Restart();
        }
    }
}


void Game::Draw()
{
    BeginDrawing();
    ClearBackground(BLACK);

    // Draw paddle
    paddle.Draw();

    // Draw bricks
    for (unsigned int k{0}; k < numberOfLines * numberOfColumns; ++k) {
        bricks[k].Draw();
    };

    // draw best score & score
    std::string bestScoreStr = std::to_string(bestScore);
    DrawText(("Best score : " + bestScoreStr).c_str(), 10, 30, 20, RED);
    DrawScore();

    if(running) {
        // Draw ball
        ball.Draw();
    } else {
        // Draw text
        DrawText("game over", 200, 350, 60, YELLOW);
        DrawText("press space to restart", 200, 430, 20, YELLOW);
    }
    EndDrawing();
}


void Game::InitBricks()
{
    unsigned int n = 0;
    Color colors[8] = {RED, RED, ORANGE, ORANGE, GREEN, GREEN, YELLOW, YELLOW};

    for (unsigned int l{0}; l < numberOfLines; ++l) 
    {
        for (unsigned int c{0}; c < numberOfColumns; ++c) 
        {
            bricks[n] = Brick();
            bricks[n].SetXPosition(10 + c * (bricks[n].GetRectangle().width + xGapBetweenBricks));
            bricks[n].SetYPosition(120 + l * (bricks[n].GetRectangle().height + yGapBetweenBricks));
            bricks[n].SetColor(colors[l]);
			++n;
		};
	};
}


void Game::GameOver()
{
    running = false;
    if(score > bestScore) {
        SetBestScore(score);
    }
}

void Game::Restart() 
{
    // Reset ball, paddle and score
    ball.SetXPosition(GetScreenWidth() / 2);
    ball.SetYPosition(GetScreenHeight() / 2);
    ball.SetXSpeed(30.0f);
    ball.SetYSpeed(400.0f);
    paddle.SetXPosition((GetScreenWidth() / 2) - paddle.GetRectangle().width / 2);
    score = 0;
    DrawScore();

    //reset bricks
    InitBricks();

    // get the best score
    bestScore = GetBestScore();

    running = true;
}


// COLLISIONS
void Game::ManageCollisionBallWall()
{
    if (ball.GetRectangle().x < 0) 
    {
        ball.SetXPosition(0.0f);
        ball.SetXSpeed(-1 * ball.GetSpeed().x);
    } 
    else if (ball.GetRectangle().x > GetScreenWidth() - ball.GetRectangle().width) 
    {
        ball.SetXPosition(GetScreenWidth() - ball.GetRectangle().width);
        ball.SetXSpeed(-1 * ball.GetSpeed().x);
    };
    if (ball.GetRectangle().y < 0) 
    {
        ball.SetYPosition(0.0f);
        ball.SetYSpeed(-1 * ball.GetSpeed().y);
    }
    else if (ball.GetRectangle().y > GetScreenHeight() - ball.GetRectangle().height) 
    {
        GameOver();
    };
}


void Game::ManageCollisionBallPaddle()
{
    if (CheckCollisionRecs(ball.GetRectangle(), paddle.GetRectangle()))
    {
        if (ball.GetSpeed().y > 0) //prevent the ball from boncing inside the paddle
        {
            ball.SetYSpeed(-1 * ball.GetSpeed().y);
            if (ball.GetRectangle().x - paddle.GetRectangle().x < paddle.GetRectangle().width / 2) 
            {
                ball.SetXSpeed(-10 * abs(ball.GetRectangle().x - paddle.GetRectangle().x - paddle.GetRectangle().width / 2));
            }
            else {
                ball.SetXSpeed(10 * abs(ball.GetRectangle().x - paddle.GetRectangle().x - paddle.GetRectangle().width / 2));
            }
        };
    };
}


void Game::ManageCollisionBallBrick()
{
    for (unsigned int k{0}; k < numberOfLines * numberOfColumns; ++k)
    {
        if (CheckCollisionRecs(ball.GetRectangle(), bricks[k].GetRectangle()))
        {
            // bounce
            ball.SetYSpeed(-1 * ball.GetSpeed().y);
            // delete brick
            bricks[k].SetYPosition(-100.0f);
            // manage score
            ++score;
        }
    };
}


void Game::DrawScore()
{
    std::string scoreStr = std::to_string(score);
    DrawText(scoreStr.c_str(), 330, 30, 30, WHITE);
}


int unsigned Game::GetBestScore()
{
    // Get the USERPROFILE environment variable to find the user's home directory & create path
    const char* userProfile = std::getenv("USERPROFILE");
    if (userProfile == nullptr) {
        std::cout << "Failed to get USERPROFILE!";
    }
    std::string path = std::string(userProfile) + "\\Documents\\best_score.txt";

    // check if the file already exist
    std::ifstream rFile(path);
    if (rFile.is_open())
    {
        std::string strValue;
        rFile >> strValue;
        rFile.close();
        int intValue = std::stoi(strValue);
        return intValue;
    }
    else
    {
        rFile.close();
        // Create the file if needed
        std::ofstream wFile;
        wFile.open(path);
        wFile << "0";
        wFile.close();
        return 0;
    }
}

void Game::SetBestScore(int _score)
{
    // Get the USERPROFILE environment variable to find the user's home directory & create path
    const char* userProfile = std::getenv("USERPROFILE");
    if (userProfile == nullptr) {
        std::cout << "Failed to get USERPROFILE!";
    }
    std::string path = std::string(userProfile) + "\\Documents\\best_score.txt";

    // check if the file already exist
    std::ifstream rFile(path);
    if (rFile.is_open())
    {
        rFile.close();
        std::ofstream wFile;
        wFile.open(path);
        wFile << std::to_string(_score); 
        wFile.close();
    }
    else
    {
        std::cout << "ERROR" << std::endl;
    }
}