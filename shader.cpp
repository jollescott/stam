#include "shader.h"

#include <glad/glad.h>

#include <fstream>

Shader::Shader()
{

}

Shader* Shader::fromSource(std::string name)
{
    std::ifstream vertFile (name.append(".vert"));

    std::string vertSource ((std::istreambuf_iterator<char>(vertFile) ),
                            (std::istreambuf_iterator<char>()));


    std::ifstream fragFile(name.append(".frag"));

    std::string fragSource ((std::istreambuf_iterator<char>(fragFile) ),
                            (std::istreambuf_iterator<char>()));

    unsigned int vertShader, fragShader;


    Shader* shader = new Shader();
    return shader;
}

int Shader::programId() const
{
    return mProgramId;
}

void Shader::setProgramId(int programId)
{
    mProgramId = programId;
}
