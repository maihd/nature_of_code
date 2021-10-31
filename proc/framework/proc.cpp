#include <raylib.h>

#include "proc.h"

extern void setup();
extern void draw();

int main()
{
    InitWindow(800, 600, "ProC Window");
    SetTargetFPS(60);

    for (int i = 0; i < 2; i++)
    {
        BeginDrawing();
        {
            ClearBackground(WHITE);
        }
        EndDrawing();
    }

    setup();

    while (!WindowShouldClose())
    {
        BeginDrawing();
        {
            draw();
        }
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
