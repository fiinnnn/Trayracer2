#include "render_command.h"

#include "core/core.h"

namespace Trayracer2 {

class RendererAPI;

Scope<RendererAPI> RenderCommand::m_rendererAPI = RendererAPI::create();

}
