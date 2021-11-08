#include <Framework/Random.h>

float NextPerlinNoise(float x)
{
    return NextPerlinNoise3(x, 0.0f, 0.0f);
}

float NextPerlinNoise2(float x, float y)
{
    return NextPerlinNoise2(x, y, 0.0f);
}

float NextPerlinNoise3(float x, float y)
{
    return 0.0f;
}
