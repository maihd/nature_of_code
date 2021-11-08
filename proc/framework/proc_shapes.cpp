#include <raylib.h>

#include "proc.h"

static Color fill_color     = { 0 };
static Color stroke_color   = { 0 };

void fill(int rgb, int a)
{
    fill(rgb, rgb, rgb, a);
}

void fill(int r, int g, int b, int a)
{
    fill_color = GetColor((r << 24) | (g << 16) | (b << 8) | a);
}

void stroke(int rgb, int a)
{
    stroke(rgb, rgb, rgb, a);
}

void stroke(int r, int g, int b, int a)
{
    stroke_color = GetColor((r << 24) | (g << 16) | (b << 8) | a);
}

void no_fill()
{
    fill_color = { 0 };
}

void no_stroke()
{
    stroke_color = { 0 };
}

void background(int rgb, int a)
{
    background(rgb, rgb, rgb, a);
}

void background(int r, int g, int b, int a)
{
    const Color color = GetColor((r << 24) | (g << 16) | (b << 8) | a);
    ClearBackground(color);
}

void point(float x, float y)
{
    DrawRectangle((int)x, (int)y, 1, 1, fill_color);
}
