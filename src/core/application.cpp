#include "application.h"

#include <glm/glm.hpp>

#include <memory>

#include "core.h"
#include "window.h"

#include "events/events.h"

#include "input/input.h"

#include "imgui/imgui_renderer.h"

#include "rendering/render_command.h"
#include "rendering/texture2d.h"

#include "gui/viewport.h"
#include "gui/dockspace.h"

namespace Trayracer2 {

Application* Application::m_instance = nullptr;

Application::Application()
{
    ASSERT(!m_instance, "Application already exists");
    m_instance = this;

    m_window = std::unique_ptr<Window>(Window::create());
    m_window->setEventCallback(BIND_EVENT_FN(Application::onEvent));

    m_imguiRenderer = createScope<ImGuiRenderer>();

    m_renderTargetTexture = Texture2D::create(512, 512);

    // temporary test texture
    float buffer[512 * 512 * 3];
    for (int i = 0; i < 512 * 512 * 3; i += 3) {
        if (i % 10) {
            buffer[i] = 1.0;
            buffer[i + 1] = 0.5;
            buffer[i + 3] = 0.0;
        }
    }

    m_renderTargetTexture->update((void*) buffer);

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
        Viewport::show("Viewport", m_renderTargetTexture->getID());

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
