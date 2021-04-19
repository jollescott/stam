#ifndef GEOMETRY_H
#define GEOMETRY_H

class Geometry
{
public:
    Geometry();

    void init();
    void prepare();

    int *indices() const;
    void setIndices(int *indices);

    float *vertices() const;
    void setVertices(float *vertices);

    unsigned int vao() const;

private:
    int* mIndices;
    float* mVertices;

    unsigned int mVBO, mEBO, mVAO;
};

#endif // GEOMETRY_H
