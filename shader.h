#ifndef SHADER_H
#define SHADER_H

#include <string>

class Shader
{
public:
    Shader();

    bool init();
    void shutdown();

    static bool fromSource(const char *filename, Shader *shader);

    int programId() const;
    void setProgramId(int programId);

private:

    int mProgramId;
};

#endif // SHADER_H
