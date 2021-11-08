#include "framework/proc.h"

void setup()
{
    set_size(400, 400);
    set_title("ProC Test");
}

void draw()
{
    background(255);
    
    no_stroke();
    fill(0);
    point(200, 200);
}
