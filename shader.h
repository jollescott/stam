#ifndef SHADER_H
#define SHADER_H

#include <string>

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

class Shader
{
public:
    Shader(std::string name);

    bool init();
    void shutdown();

    int programId() const;
    void setProgramId(int programId);

    void setMat4(std::string name, glm::mat4 mat);

private:
    std::string mName;
    int mProgramId;
};

#endif // SHADER_H
