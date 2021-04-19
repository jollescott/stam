#include "shader.h"

#include <glad/glad.h>

#include <fstream>

Shader::Shader()
{

}

bool Shader::init()
{
    return true;
}

void Shader::shutdown()
{
    glDeleteProgram(programId());
}

bool Shader::fromSource(const char *filename, Shader *shader)
{
    std::string name(filename);

    std::ifstream vertFile (name.append(".vert"));

    std::string vertSource ((std::istreambuf_iterator<char>(vertFile) ),
                            (std::istreambuf_iterator<char>()));


    std::ifstream fragFile(name.append(".frag"));

    std::string fragSource ((std::istreambuf_iterator<char>(fragFile) ),
                            (std::istreambuf_iterator<char>()));

    int success;
    char compileMsg[512];

    unsigned int vertShader = glCreateShader(GL_VERTEX_SHADER);

    const char *vertChar = vertSource.c_str();
    glShaderSource(vertShader, 1, &vertChar, NULL);
    glCompileShader(vertShader);

    glGetShaderiv(vertShader, GL_COMPILE_STATUS, &success);

    if(!success) {
       glGetShaderInfoLog(vertShader, 512, NULL, compileMsg);
       printf("Shader compile error %s", compileMsg);

       return false;
    }

    unsigned int fragShader = glCreateShader(GL_FRAGMENT_SHADER);

    const char *fragChar = fragSource.c_str();
    glShaderSource(fragShader, 1, &fragChar, NULL);
    glCompileShader(fragShader);

    if(!success) {
        glGetShaderInfoLog(fragShader, 512, NULL, compileMsg);
        printf("Shader compile error %s", compileMsg);

        return false;
    }

    unsigned int shaderProgramId = glCreateProgram();

    glAttachShader(shaderProgramId, vertShader);
    glAttachShader(shaderProgramId, fragShader);
    glLinkProgram(shaderProgramId);

    glGetProgramiv(shaderProgramId, GL_LINK_STATUS, &success);

    if(!success) {
        glGetProgramInfoLog(shaderProgramId, 512, NULL, compileMsg);
        printf("Shader link error %s", compileMsg);

        return false;
    }

    glDeleteShader(vertShader);
    glDeleteShader(fragShader);

    shader = new Shader();
    shader->setProgramId(shaderProgramId);

    return true;
}

int Shader::programId() const
{
    return mProgramId;
}

void Shader::setProgramId(int programId)
{
    mProgramId = programId;
}
