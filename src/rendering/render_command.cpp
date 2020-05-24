#include "render_command.h"

#include "platform/opengl/opengl_renderer_api.h"

namespace Trayracer2 {

class RendererAPI;

RendererAPI* RenderCommand::m_rendererAPI = new OpenGLRendererAPI();

}
