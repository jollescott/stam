#include "geometry.h"

#include <iterator>
#include <glad/glad.h>

Geometry::Geometry()
{

}

void Geometry::init()
{
    glGenVertexArrays(1, &mVAO);
    glGenBuffers(1, &mVBO);
    glGenBuffers(1, &mEBO);
}

int *Geometry::indices() const
{
    return mIndices;
}

void Geometry::setIndices(int *indices)
{
    mIndices = indices;
}

float *Geometry::vertices() const
{
    return mVertices;
}

void Geometry::setVertices(float *vertices)
{
    mVertices = vertices;
}

void Geometry::prepare()
{
    glBindVertexArray(mVAO);

    glBindBuffer(GL_ARRAY_BUFFER, mVBO);

    if(mVertices != NULL) {
        glBufferData(GL_ARRAY_BUFFER, sizeof (mVertices), mVertices, GL_STATIC_DRAW);
    }

    if(mIndices) {
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(mIndices), mIndices, GL_STATIC_DRAW);
    }

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glBindVertexArray(0);
}

unsigned int Geometry::vao() const
{
    return mVAO;
}

