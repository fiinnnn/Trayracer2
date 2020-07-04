#ifndef RENDERER_API_H
#define RENDERER_API_H

#include <glm/glm.hpp>

#include "core/core.h"

namespace Trayracer2 {

class RendererAPI {
public:
    enum class API {
        None   = 0,
        OpenGL = 1
    };

public:
    virtual ~RendererAPI() = default;

    virtual void init() = 0;

    virtual void setClearColor(const glm::vec4& color) = 0;
    virtual void clear() = 0;

    static API getAPI()
    { return m_api; }
    static Scope<RendererAPI> create();

private:
    static API m_api;
};

}

#endif //RENDERER_API_H
