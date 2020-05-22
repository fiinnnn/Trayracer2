#include "linux_window.h"

#include <memory>

#include "core.h"

namespace Trayracer2
{

static bool glfwInitialized;

static void glfwErrorCallback(int e, const char* desc)
{
	LOG_ERROR("GLFW error ({0}): {1}", e, desc);
}

Window* Window::create(const WindowCfg& cfg)
{
	return new LinuxWindow(cfg);
}

LinuxWindow::LinuxWindow(const WindowCfg &cfg)
{
	init(cfg);
}

LinuxWindow::~LinuxWindow()
{
	close();
}

void LinuxWindow::init(const WindowCfg &cfg)
{
	m_data.title = cfg.title;
	m_data.width = cfg.width;
	m_data.height = cfg.height;

	LOG_INFO("Initializing window: {0} ({1} x {2})",
			m_data.title, m_data.width, m_data.height);

	if (!glfwInitialized) {
		int success = glfwInit();
		ASSERT(success, "Failed to initialize GLFW");
		glfwSetErrorCallback(glfwErrorCallback);
		glfwInitialized = true;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	m_window = glfwCreateWindow((int)m_data.width, (int)m_data.height,
			m_data.title.c_str(), nullptr, nullptr);

	//TODO: initialize OpenGL context

	glfwSetWindowUserPointer(m_window, &m_data);

	//setVsync(true);

	//TODO: setup event handlers
}

void LinuxWindow::close()
{
	glfwDestroyWindow(m_window);
	LOG_INFO("Closed window: {0}", m_data.title);
}

void LinuxWindow::update()
{
	glfwPollEvents();
	//TODO: swap buffers
}

void LinuxWindow::setVsync(bool enabled)
{
	if (enabled)
		glfwSwapInterval(1);
	else
		glfwSwapInterval(0);

	m_data.vsync = enabled;
}

}
