#include "application.h"

#include <glad/glad.h>
#include <imgui.h>

#include <memory>

#include "core.h"
#include "window.h"
#include "events/events.h"
#include "input/input.h"
#include "imgui/imgui_renderer.h"

namespace Trayracer2 {

Application* Application::m_instance = nullptr;

Application::Application()
{
	ASSERT(!m_instance, "Application already exists");
	m_instance = this;

	m_window = std::unique_ptr<Window>(Window::create());
	m_window->setEventCallback(BIND_EVENT_FN(Application::onEvent));

	m_imguiRenderer = createScope<ImGuiRenderer>();

	LOG_INFO("Application initialized");
}

Application::~Application() = default;

void Application::run()
{
	while (m_running) {
		m_window->update();

		handleEvents();

		if (Input::keyPressed(KEY_ESCAPE))
			m_running = false;

		glClearColor(0.2, 0.2, 0.2, 1.0);
		glClear(GL_COLOR_BUFFER_BIT);

		m_imguiRenderer->begin();
		bool show = true;
		ImGui::ShowDemoWindow(&show);
		m_imguiRenderer->end();
	}
}

void Application::onEvent(const Ref<Event>& e)
{
	m_eventQueue.push(e);
}

void Application::handleEvents()
{
	while (!m_eventQueue.empty()) {
		Ref<Event> e = m_eventQueue.front();

		EventDispatcher d(*e);
		d.dispatch<WindowClosedEvent>(BIND_EVENT_FN(Application::onWindowClosed));

		m_eventQueue.pop();
	}
}

bool Application::onWindowClosed(WindowClosedEvent &e)
{
	m_running = false;
	return true;
}

}
