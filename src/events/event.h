#ifndef EVENT_H
#define EVENT_H

#include <string>
#include <ostream>

namespace Trayracer2 {

enum class EventType {
    None,
    WindowClosed,
    WindowResized,
    KeyPressed,
    KeyReleased,
    KeyTyped,
    MousePressed,
    MouseReleased,
    MouseMoved,
    MouseScrolled
};

enum EventCategory {
    None,
    ECApplication = (1 << 0),
    ECInput       = (1 << 1),
    ECKeyboard    = (1 << 2),
    ECMouse       = (1 << 3)
};


class Event {
    friend class EventDispatcher;

public:
    virtual ~Event() = default;

    [[nodiscard]] virtual EventType getType() const = 0;

    [[nodiscard]] virtual int getCategories() const = 0;

    [[nodiscard]] virtual std::string toString() const = 0;

    [[nodiscard]] inline bool handled() const
    { return m_handled; }

protected:
    bool m_handled = false;
};

inline std::ostream& operator<<(std::ostream& os, const Event& e)
{
    return os << e.toString();
}

}

#endif //EVENT_H
