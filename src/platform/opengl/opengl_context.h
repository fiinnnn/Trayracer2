#ifndef OPENGL_CONTEXT_H
#define OPENGL_CONTEXT_H

#include "rendering/graphics_context.h"

class GLFWwindow;

namespace Trayracer2 {

class OpenGLContext : public GraphicsContext {
public:
    explicit OpenGLContext(GLFWwindow* windowHandle);

    void init() override;
    void swapBuffers() override;

private:
    GLFWwindow* m_windowHandle;
};

}


#endif //OPENGL_CONTEXT_H
