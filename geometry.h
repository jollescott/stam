#ifndef GEOMETRY_H
#define GEOMETRY_H

class Geometry
{
public:
    Geometry();

    void init();

    int *indices() const;
    void setIndices(int *indices);

    float *vertices() const;
    void setVertices(float *vertices);

    unsigned int vao() const;

private:

    void prepare();

    int* mIndices;
    float* mVertices;

    unsigned int mVBO, mEBO, mVAO;
};

#endif // GEOMETRY_H
