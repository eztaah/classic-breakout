#include "game.hpp"
#include <raylib.hpp>
#include <iostream>


int main()
{
    InitWindow(700, 800, "Breakout");
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