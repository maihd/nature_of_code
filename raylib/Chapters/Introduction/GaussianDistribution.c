#include <raylib.h>

int main()
{
    enum { SCREEN_WIDTH = 600, SCREEN_HEIGHT = 240 };

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Gaussian Distribution");

    while (!WindowShouldClose())
    {
        BeginDrawing();
        {
            ClearBackground(RAYWHITE);
        }
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
