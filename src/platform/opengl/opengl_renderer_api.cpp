#include "opengl_renderer_api.h"

#include <glad/glad.h>

namespace Trayracer2 {

void OpenGLRendererAPI::setClearColor(const glm::vec4 &color)
{
	glClearColor(color.r, color.g, color.b, color.a);
}

void OpenGLRendererAPI::clear()
{
	glClear(GL_COLOR_BUFFER_BIT);
}

}