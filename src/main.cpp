#include "game.hpp"
#include <raylib.h>

// VARIABLES AND FUNCTIONS
const unsigned int screenWidth = 700;
const unsigned int screenHeight = 800;

int main()
{
    InitWindow(screenWidth, screenHeight, "Breakout");
    SetWindowState(FLAG_VSYNC_HINT);

    Game game = Game();

    while (!WindowShouldClose())
    {
        // update
        game.Update();

        // restart
        if (IsKeyDown(KEY_SPACE) && !game.running) {
            game.Restart();
        };

        // Drawing
        game.Draw();
    }
    CloseWindow();
    return 0;
}