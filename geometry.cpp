#include "geometry.h"

Geometry::Geometry()
{
    mVertices = std::vector<float> {
            0.5f,  0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
           -0.5f, -0.5f, 0.0f,
           -0.5f,  0.5f, 0.0f
    };

    mIndices = std::vector<unsigned int> {
            0, 1, 3,
            1, 2, 3
};
}

bool Geometry::init()
{
    unsigned int vbo, ebo;

    glGenBuffers(1, &vbo);
    glGenBuffers(1, &ebo);

    glGenVertexArrays(1, &mVAO);
    glBindVertexArray(mVAO);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, mVertices.size() * sizeof(float), mVertices.data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, mIndices.size() * sizeof(unsigned int), mIndices.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    mShader = new Shader("color");

    if(!mShader->init()) {
        return false;
    }

    return true;
}

void Geometry::shutdown()
{
    delete mShader;
    mShader = nullptr;
}

Shader *Geometry::shader() const
{
    return mShader;
}

void Geometry::setShader(Shader *shader)
{
    mShader = shader;
}

unsigned int Geometry::vao() const
{
    return mVAO;
}
