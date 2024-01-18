#include <iostream>
#include "raylib.h"

int main()
{
    const int screenWidth{ 1240 };
    const int screenHeight{ 800 };

    InitWindow(screenWidth, screenHeight, "Brick Breaker!");
    SetTargetFPS(60);


    while (WindowShouldClose() == false)
    {
        const float deltaTime{ GetFrameTime() };

        BeginDrawing();
        ClearBackground(WHITE);


        DrawFPS(10, 10);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}

