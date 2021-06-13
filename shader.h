#ifndef SHADER_H
#define SHADER_H

#include <string>

class Shader
{
public:
    Shader(std::string name);

    bool init();
    void shutdown();

    int programId() const;
    void setProgramId(int programId);

private:
    std::string mName;
    int mProgramId;
};

#endif // SHADER_H
