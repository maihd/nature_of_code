#include <raylib.h>

int main()
{
    enum { SCREEN_WIDTH = 640, SCREEN_HEIGHT = 240 };

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "RandomNumberDistribution");
    SetTargetFPS(60);

    enum { RANDOM_COUNT = 20 };
    int randomCounts[RANDOM_COUNT];
    for (int i = 0; i < RANDOM_COUNT; i++)
    {
        randomCounts[i] = 0;
    }

    while (!WindowShouldClose())
    {
        const int index = GetRandomValue(0, RANDOM_COUNT - 1);
        randomCounts[index]++;

        BeginDrawing();
        {
            ClearBackground(RAYWHITE);

            const int w = SCREEN_WIDTH / RANDOM_COUNT;
            for (int i = 0; i < RANDOM_COUNT; i++)
            {
                const int h = randomCounts[i] < SCREEN_HEIGHT ? randomCounts[i] : SCREEN_HEIGHT;
                DrawRectangle(w * i, SCREEN_HEIGHT - h, w, h, GRAY);
                DrawRectangleLines(w* i, SCREEN_HEIGHT - h, w, h, BLACK);
            }
        }
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
