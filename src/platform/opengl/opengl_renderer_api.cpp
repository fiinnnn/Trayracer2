#include "opengl_renderer_api.h"

#include <glad/glad.h>

namespace Trayracer2 {

void glMessageCallback(
        unsigned source,
        unsigned type,
        unsigned id,
        unsigned severity,
        int length,
        const char* message,
        const void* userParam)
{
    switch (severity) {
        case GL_DEBUG_SEVERITY_HIGH: LOG_CRIT(message); return;
        case GL_DEBUG_SEVERITY_MEDIUM: LOG_ERROR(message); return;
        case GL_DEBUG_SEVERITY_LOW: LOG_WARN(message); return;
        case GL_DEBUG_SEVERITY_NOTIFICATION: LOG_TRACE(message); return;
    }
}

void OpenGLRendererAPI::init()
{
#ifndef NDEBUG
    glEnable(GL_DEBUG_OUTPUT);
    glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
    glDebugMessageCallback(glMessageCallback, nullptr);
#endif
}

void OpenGLRendererAPI::setClearColor(const glm::vec4& color)
{
    glClearColor(color.r, color.g, color.b, color.a);
}

void OpenGLRendererAPI::clear()
{
    glClear(GL_COLOR_BUFFER_BIT);
}

}
