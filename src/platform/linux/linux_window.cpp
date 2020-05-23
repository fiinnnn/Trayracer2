#include "linux_window.h"

#include <memory>

#include "core.h"
#include "events/events.h"
#include "platform/opengl/opengl_context.h"

namespace Trayracer2 {

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

	m_context = new OpenGLContext(m_window);
	m_context->init();

	glfwSetWindowUserPointer(m_window, &m_data);

	setVsync(true);

	glfwSetWindowCloseCallback(m_window, [](GLFWwindow* window)
	{
		WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

		Ref<WindowClosedEvent> e = createRef<WindowClosedEvent>(WindowClosedEvent());
		data.eventCallback(e);
	});

	glfwSetWindowSizeCallback(m_window, [](GLFWwindow* window, int width, int height)
	{
		WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
		data.width = width;
		data.height = height;

		Ref<WindowResizedEvent> e = createRef<WindowResizedEvent>(WindowResizedEvent(width, height));
		data.eventCallback(e);
	});

	glfwSetKeyCallback(m_window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

		switch (action) {
			case GLFW_PRESS:
			{
				Ref<KeyPressedEvent> e = createRef<KeyPressedEvent>(KeyPressedEvent(key, false));
				data.eventCallback(e);
				break;
			}
			case GLFW_REPEAT:
			{
				Ref<KeyPressedEvent> e = createRef<KeyPressedEvent>(KeyPressedEvent(key, true));
				data.eventCallback(e);
				break;
			}
			case GLFW_RELEASE:
			{
				Ref<KeyReleasedEvent> e = createRef<KeyReleasedEvent>(KeyReleasedEvent(key));
				data.eventCallback(e);
				break;
			}
		}
	});

	glfwSetCharCallback(m_window, [](GLFWwindow* window, unsigned int keycode)
	{
		WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

		Ref<KeyTypedEvent> e = createRef<KeyTypedEvent>(KeyTypedEvent(keycode));
		data.eventCallback(e);
	});

	glfwSetMouseButtonCallback(m_window, [](GLFWwindow* window, int button, int action, int mods)
	{
		WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

		switch (action) {
			case GLFW_PRESS:
			{
				Ref<MousePressedEvent> e = createRef<MousePressedEvent>(MousePressedEvent(button));
				data.eventCallback(e);
				break;
			}
			case GLFW_RELEASE:
			{
				Ref<MouseReleasedEvent> e = createRef<MouseReleasedEvent>(MouseReleasedEvent(button));
				data.eventCallback(e);
				break;
			}
		}
	});

	glfwSetCursorPosCallback(m_window, [](GLFWwindow* window, double x, double y)
	{
		WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

		Ref<MouseMovedEvent> e = createRef<MouseMovedEvent>(MouseMovedEvent((float)x, (float)y));
		data.eventCallback(e);
	});

	glfwSetScrollCallback(m_window, [](GLFWwindow* window, double xOffset, double yOffset)
	{
		WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

		Ref<MouseScrolledEvent> e = createRef<MouseScrolledEvent>(MouseScrolledEvent((float)xOffset, (float)yOffset));
		data.eventCallback(e);
	});
}

void LinuxWindow::close()
{
	glfwDestroyWindow(m_window);
	LOG_INFO("Closed window: {0}", m_data.title);
}

void LinuxWindow::update()
{
	glfwPollEvents();
	m_context->swapBuffers();
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
