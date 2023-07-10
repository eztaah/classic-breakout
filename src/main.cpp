#include <raylib.h>
#include "../include/game.hpp"

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
        BeginDrawing();

        // update
        game.Update();

        // restart
        if (IsKeyDown(KEY_SPACE) && !game.running) {
            game.Restart();
        };

        // Drawing
        ClearBackground(BLACK);
        game.Draw();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}