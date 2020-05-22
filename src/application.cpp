#include "application.h"

#include "core.h"

namespace Trayracer2 {

Application* Application::m_instance = nullptr;

Application::Application()
{
	ASSERT(!m_instance, "Application already exists");
	m_instance = this;

	m_window = std::unique_ptr<Window>(Window::create());

	LOG_INFO("Application initialized");
}

Application::~Application()
{

}

void Application::run()
{
	//TODO: main application loop
	/*while (m_running) {
		m_window->update();
	}*/
}

}
