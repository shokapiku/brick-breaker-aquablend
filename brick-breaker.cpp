#include <iostream>
#include "raylib.h"
#include "Level.h"

int main()
{
    const int screenWidth{ 1240 };
    const int screenHeight{ 800 };

    InitWindow(screenWidth, screenHeight, "Brick Breaker!");
    SetTargetFPS(60);

    Level level(screenWidth, screenHeight);

    while (WindowShouldClose() == false)
    {
        const float deltaTime{ GetFrameTime() };

        BeginDrawing();
        ClearBackground(WHITE);

        level.draw();

        DrawFPS(10, 10);
        EndDrawing();
    }

    level.unload();

    CloseWindow();
    return 0;
}

