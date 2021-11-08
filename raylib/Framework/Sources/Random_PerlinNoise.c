#include <Framework/Random.h>

#include <math.h>
#include <raylib.h>

#define PERLIN_YWRAPB   (4)
#define PERLIN_YWRAP    (1 << PERLIN_YWRAPB)
#define PERLIN_ZWRAPB   (8)
#define PERLIN_ZWRAP    (1 << PERLIN_ZWRAPB)
#define PERLIN_SIZE     (4095)

static float ScaledCosine(x)
{
    return 0.5f * (1.0f - cosf(x * PI));
}

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
