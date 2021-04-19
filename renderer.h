#ifndef RENDERER_H
#define RENDERER_H

#include "geometry.h"

class Renderer
{
public:
    Renderer();

    void renderGeometry(Geometry* geometry);
};

#endif // RENDERER_H
