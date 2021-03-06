#include "application.h"

#include <glm/glm.hpp>

#include "core.h"
#include "window.h"

#include "events/events.h"

#include "input/input.h"

#include "imgui/imgui_renderer.h"

#include "rendering/render_command.h"

#include "gui/gui.h"

namespace Trayracer2 {

Application* Application::m_instance = nullptr;

Application::Application()
{
    ASSERT(!m_instance, "Application already exists");
    m_instance = this;

    m_window = Scope<Window>(Window::create());
    m_window->setEventCallback(BIND_EVENT_FN(Application::onEvent));

    RenderCommand::init();

    m_raytracer = createScope<Raytracer>();

    m_imguiRenderer = createScope<ImGuiRenderer>();

    m_gui = createScope<GUI>();

    LOG_INFO("Application initialized");
}

Application::~Application() = default;

void Application::run()
{
    while (m_running) {
        m_window->update();

        handleEvents();

        RenderCommand::setClearColor(glm::vec4(0.2, 0.2, 0.2, 1.0));
        RenderCommand::clear();

        m_imguiRenderer->begin();

        m_gui->show(*m_raytracer);

        m_raytracer->trace();

        m_imguiRenderer->end();
    }
}

void Application::exit() {
    m_running = false;
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
        d.dispatch<WindowClosedEvent>(
                BIND_EVENT_FN(Application::onWindowClosed));

        m_eventQueue.pop();
    }
}

bool Application::onWindowClosed(WindowClosedEvent& e)
{
    m_running = false;
    return true;
}

}
