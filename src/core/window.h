#ifndef WINDOW_H
#define WINDOW_H

#include <string>
#include <functional>

#include "core.h"

namespace Trayracer2 {

class Event;

struct WindowCfg {
    std::string title;
    unsigned int width, height;

    explicit WindowCfg(const std::string& windowTitle = "Trayracer2",
                       unsigned int w = 1280,
                       unsigned int h = 720) : title(windowTitle), width(w),
                                               height(h)
    {}
};

class Window {
public:
    static Window* create(const WindowCfg& cfg = WindowCfg());

    virtual ~Window() = default;;

    virtual void update() = 0;

    [[nodiscard]] virtual unsigned int getWidth() const = 0;
    [[nodiscard]] virtual unsigned int getHeight() const = 0;

    virtual void setVsync(bool enabled) = 0;
    [[nodiscard]] virtual bool getVsync() const = 0;

    using EventCallback = std::function<void(Ref < Event > )>;
    virtual void setEventCallback(const EventCallback& callback) = 0;

    [[nodiscard]] virtual void* getNativeWindow() const = 0;
};

}

#endif //WINDOW_H
