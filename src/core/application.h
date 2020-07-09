#ifndef APPLICATION_H
#define APPLICATION_H

#include <memory>
#include <queue>

#include "core.h"
#include "gui/gui.h"

namespace Trayracer2 {

class Window;
class Event;
class WindowClosedEvent;
class ImGuiRenderer;
class Texture2D;
class Raytracer;

class Application {
public:
    Application();

    virtual ~Application();

    void run();

    void exit();

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

    Scope<Raytracer> m_raytracer;

    Scope<ImGuiRenderer> m_imguiRenderer;

    Scope<GUI> m_gui;
};

}

#endif //APPLICATION_H
