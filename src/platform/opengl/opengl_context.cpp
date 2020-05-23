#include "opengl_context.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include "core.h"

namespace Trayracer2
{

OpenGLContext::OpenGLContext(GLFWwindow *windowHandle)
	: m_windowHandle(windowHandle)
{
	ASSERT(windowHandle, "Window handle is null");
}

void OpenGLContext::init()
{
	glfwMakeContextCurrent(m_windowHandle);

	int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	ASSERT(status, "Failed to initialize GLAD");

	LOG_INFO("OpenGL:");
	LOG_INFO("\tVendor: {0}", glGetString(GL_VENDOR));
	LOG_INFO("\tVersion: {0}", glGetString(GL_VERSION));
	LOG_INFO("\tRenderer: {0}", glGetString(GL_RENDERER));
}

void OpenGLContext::swapBuffers()
{
	glfwSwapBuffers(m_windowHandle);
}

}
