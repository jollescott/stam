#ifndef SHADER_H
#define SHADER_H

#include <string>

class Shader
{
public:
    Shader();

    static Shader* fromSource(std::string filename);

    int programId() const;
    void setProgramId(int programId);

private:

    int mProgramId;
};

#endif // SHADER_H
