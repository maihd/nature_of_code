#include <raylib.h>

typedef enum WalkDirection
{
    WALK_LEFT,
    WALK_RIGHT,
    WALK_UP,
    WALK_DOWN,

    WALK_DIRECTION_COUNT,
} WalkDirection;

typedef struct Walker
{
    float x;
    float y;
} Walker;

static void StepWalker(Walker* walker, float distance)
{
    WalkDirection direction = GetRandomValue(0, WALK_DIRECTION_COUNT - 1);
    switch (direction)
    {
        case WALK_LEFT:
            walker->x -= distance;
            break;

        case WALK_RIGHT:
            walker->x += distance;
            break;

        case WALK_UP:
            walker->y -= distance;
            break;

        case WALK_DOWN:
            walker->y += distance;
            break;
    }
}

static void DrawWalker(Walker walker)
{
    DrawCircle((int)walker.x, (int)walker.y, 1.0f, BLACK);
}

int main(char* argv[], int argc)
{
    InitWindow(800, 600, "Random Walk");
    SetTargetFPS(60);
    
    // We need a canvas to draw in it, that canvas wont be clear frame after frame
    RenderTexture2D renderTexture = LoadRenderTexture(GetScreenWidth(), GetScreenHeight());

    Walker walker = { .x = (float)GetScreenWidth() * 0.5f, .y = (float)GetScreenHeight() * 0.5f }; 

    while (!WindowShouldClose())
    {
        StepWalker(&walker, GetFrameTime() * 60.0f);

        BeginDrawing();
        {
            ClearBackground(RAYWHITE);

            // Offscreen drawing on the canvas
            BeginTextureMode(renderTexture);
            {
                DrawWalker(walker);
            }
            EndTextureMode();

            // Present the canvas on the screen
            DrawTexture(renderTexture.texture, 0, 0, WHITE);
        }
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
