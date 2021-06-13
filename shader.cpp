#include "shader.h"

#include <glad/glad.h>

#include <fstream>

Shader::Shader(std::string name)
{
    mName = name;
}

bool Shader::init()
{
    std::ifstream vertFile ("assets/shaders/" + mName + ".vert");

    std::string vertSource ((std::istreambuf_iterator<char>(vertFile) ),
                            (std::istreambuf_iterator<char>()));


    std::ifstream fragFile("assets/shaders/" + mName + ".frag");

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

    mProgramId = glCreateProgram();

    glAttachShader(mProgramId, vertShader);
    glAttachShader(mProgramId, fragShader);

    glLinkProgram(mProgramId);

    glGetProgramiv(mProgramId, GL_LINK_STATUS, &success);

    if(!success) {
        glGetProgramInfoLog(mProgramId, 512, NULL, compileMsg);
        printf("Shader link error %s", compileMsg);

        return false;
    }

    glDeleteShader(vertShader);
    glDeleteShader(fragShader);

    return true;
}

void Shader::shutdown()
{
    glDeleteProgram(programId());
}

int Shader::programId() const
{
    return mProgramId;
}

void Shader::setProgramId(int programId)
{
    mProgramId = programId;
}
