#include <iostream>
#include "raylib.h"
#include "StateManager.h"

int main()
{
    const int screenWidth{ 1240 };
    const int screenHeight{ 800 };

    InitWindow(screenWidth, screenHeight, "Brick Breaker!");
    SetTargetFPS(60);

    StateManager game;

    while (WindowShouldClose() == false)
    {
        const float deltaTime{ GetFrameTime() };

        game.update(deltaTime);

        BeginDrawing();
        ClearBackground(WHITE);

        game.draw();

        DrawFPS(10, 10);
        EndDrawing();
    }

    game.unload();

    CloseWindow();
    return 0;
}

