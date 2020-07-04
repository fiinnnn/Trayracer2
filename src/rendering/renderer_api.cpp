#include "renderer_api.h"

#include "platform/opengl/opengl_renderer_api.h"

namespace Trayracer2 {

RendererAPI::API RendererAPI::m_api = RendererAPI::API::OpenGL;

Scope<RendererAPI> RendererAPI::create()
{
    switch (m_api) {
        case RendererAPI::API::None:
            ASSERT(false, "RendererAPI::None is not supported");
            return nullptr;
        case RendererAPI::API::OpenGL:
            return createScope<OpenGLRendererAPI>();
    }
}

}
