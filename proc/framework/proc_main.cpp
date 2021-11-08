#include <raylib.h>

#include "proc.h"

extern void setup();
extern void draw();

static int frame_count = 0;

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
        frame_count++;

        BeginDrawing();
        {
            draw();
        }
        EndDrawing();
    }

    CloseWindow();
    return 0;
}

void set_size(int width, int height)
{
    SetWindowSize(width, height);

    const int monitor = GetCurrentMonitor();
    const int monitor_width = GetMonitorWidth(monitor);
    const int monitor_height = GetMonitorHeight(monitor);
    SetWindowPosition((monitor_width - width) / 2, (monitor_height - height) / 2);
}

void set_icon(const char* icon_path)
{
    Image image = LoadImage(icon_path);
    SetWindowIcon(image);
}

void set_title(const char* new_title)
{
    SetWindowTitle(new_title);
}

int get_width()
{
    return GetScreenWidth();
}

int get_height()
{
    return GetScreenHeight();
}

void set_frame_rate(int frame_rate)
{
    SetTargetFPS(frame_rate);
}

int get_frame_rate()
{
    return GetFPS();
}

int get_frame_count()
{
    return frame_count;
}

float get_frame_time()
{
    return GetFrameTime();
}

float get_total_time()
{
    return (float)GetTime();
}
