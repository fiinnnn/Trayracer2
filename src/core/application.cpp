#include "application.h"

#include <glm/glm.hpp>

#include <memory>

#include "core.h"
#include "window.h"

#include "events/events.h"

#include "input/input.h"

#include "imgui/imgui_renderer.h"

#include "rendering/render_command.h"

#include "gui/viewport.h"
#include "gui/dockspace.h"
#include "gui/scene_overview.h"
#include "gui/object_properties.h"
#include "gui/settings_ui.h"
#include "gui/menu_bar.h"

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

        RenderCommand::setClearColor(glm::vec4(0.2, 0.2, 0.2, 1.0));
        RenderCommand::clear();

        m_imguiRenderer->begin();

        Dockspace::show();
        Viewport::show(*m_raytracer);
        SceneOverview::show(m_raytracer->getScene());
        ObjectProperties::show();
        SettingsUI::show();
        MenuBar::show();

        //m_raytracer->trace();

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
