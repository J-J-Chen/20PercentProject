#pragma once

#include <GL/glew.h>

struct Position {
    float x;
    float y;
};

struct Color {
    GLubyte r;
    GLubyte g;
    GLubyte b;
    GLubyte a;
};

//The vertex definition
struct Vertex {
    //This is the position struct. When you store a struct or class
    //inside of another struct or class, it is called composition. This is
    //layed out exactly the same in memory as if we had a float position[2],
    //but doing it this way makes more sense.
    Position position;

    //4 bytes for r g b a color.
    Color color;
};