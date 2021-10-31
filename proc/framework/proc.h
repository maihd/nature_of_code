#pragma once

// Types

enum struct ShapeMode
{
    Center,
    Corner,
};

// System variables

float get_width();
float get_height();

float get_mouse_x();
float get_mouse_y();

// Attributes

void fill(int rgb, int a = 255);
void fill(int r, int g, int b, int a = 255);

void stroke(int rgb, int a = 255);
void stroke(int r, int g, int b, int a = 255);

void background(int rgb, int a = 255);
void background(int r, int g, int b, int a = 255);

void no_fill();
void no_stroke();

void stroke_weight(float weight);

void rect_mode(int mode);
void ellipse_mode(int mode);

void text_size(float pixels);

// Math

float map(float x, float min, float max);
float map(float x, float in_min, float in_max, float out_min, float out_max);

float random();
float random(float max);
float random(float min, float max);

float noise(float x, float y = 0.0f, float z = 0.0f);

float random_gaussian();
float random_gaussian(float mean, float stddev);

// 2d primitives

void line(float x1, float y1, float x2, float y2);
void point(float x, float y);

void rect(float x, float y, float width, float height);
void ellipse(float x, float y, float width, float height);
void arc(float x, float y, float width, float height, float start, float stop);

void begin_shape();
void end_shape();

void vertex(float x, float y);
void text(const char* string, float x, float y, float boxwidth, float boxheight);
