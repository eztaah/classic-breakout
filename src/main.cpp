#include "game.hpp"
#include <raylib.h>

// VARIABLES AND FUNCTIONS
const unsigned int screenWidth = 700;
const unsigned int screenHeight = 800;

int main()
{
    InitWindow(screenWidth, screenHeight, "Breakout");
    SetWindowState(FLAG_VSYNC_HINT);
    Game game = Game();     // ou Game game{};

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