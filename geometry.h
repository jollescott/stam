#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <vector>
#include <glad/glad.h>

#include "shader.h"

class Geometry
{
public:
    Geometry();

    bool init();
    void shutdown();

    Shader *shader() const;
    void setShader(Shader *shader);

    unsigned int vao() const;

private:
    unsigned int mVAO;

    Shader* mShader;

    std::vector<float> mVertices;
    std::vector<unsigned int> mIndices;
};

#endif // GEOMETRY_H
