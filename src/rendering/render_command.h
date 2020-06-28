#ifndef RENDER_COMMAND_H
#define RENDER_COMMAND_H

#include <glm/glm.hpp>

#include "renderer_api.h"

namespace Trayracer2 {

class RenderCommand {
public:
    inline static void setClearColor(const glm::vec4& color)
    {
        m_rendererAPI->setClearColor(color);
    }

    inline static void clear()
    {
        m_rendererAPI->clear();
    }

private:
    static RendererAPI* m_rendererAPI;
};

}

#endif //RENDER_COMMAND_H
