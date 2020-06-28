#ifndef RENDERER_API_H
#define RENDERER_API_H

#include <glm/glm.hpp>

namespace Trayracer2 {

class RendererAPI {
public:
    enum class API {
        None   = 0,
        OpenGL = 1
    };

    inline static API getAPI()
    { return m_api; }

    virtual void setClearColor(const glm::vec4& color) = 0;
    virtual void clear() = 0;

private:
    static API m_api;
};

}

#endif //RENDERER_API_H
