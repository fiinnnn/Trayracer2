#ifndef OPENGL_RENDERER_API_H
#define OPENGL_RENDERER_API_H

#include <glm/glm.hpp>

#include "rendering/renderer_api.h"

namespace Trayracer2 {

class OpenGLRendererAPI : public RendererAPI {
public:
    void setClearColor(const glm::vec4& color) override;
    void clear() override;
};

}

#endif //OPENGL_RENDERER_API_H
