#ifndef APPLICATION_H
#define APPLICATION_H

#include <memory>
#include <queue>

#include "core.h"

namespace Trayracer2 {

class Window;

class Event;

class WindowClosedEvent;

class ImGuiRenderer;

class Texture2D;

class Application {
public:
    Application();

    virtual ~Application();

    void run();

    void onEvent(const Ref<Event>& e);

    [[nodiscard]] inline static Application& get()
    { return *m_instance; }

    [[nodiscard]] inline Window& getWindow()
    { return *m_window; }

private:
    void handleEvents();

    bool onWindowClosed(WindowClosedEvent& e);

private:
    static Application* m_instance;

    bool m_running = true;

    Scope<Window> m_window;

    std::queue<Ref<Event>> m_eventQueue;

    Scope<ImGuiRenderer> m_imguiRenderer;

    Ref<Texture2D> m_renderTargetTexture;
};

}

#endif //APPLICATION_H
