#pragma once

float       NextGaussian(float x);
float       NextGaussianEx(float mean, float stddev);

float       NextPerlinNoise(float x);
float       NextPerlinNoise2(float x, float y);
float       NextPerlinNoise3(float x, float y, float z);

//float       NextSimplexNoise(float x);
//float       NextSimplexNoise2(float x, float y);
//float       NextSimplexNoise3(float x, float y, float z);
//float       NextSimplexNoise4(float x, float y, float z, float w);
