#ifndef APPLICATION_EVENTS_H
#define APPLICATION_EVENTS_H

#include <string>
#include <sstream>

#include "event.h"

namespace Trayracer2 {

class WindowClosedEvent : public Event {
public:
    WindowClosedEvent() = default;

    [[nodiscard]] static EventType getStaticType()
    { return EventType::WindowClosed; }

    [[nodiscard]] EventType getType() const override
    { return EventType::WindowClosed; }

    [[nodiscard]] int getCategories() const override
    { return EventCategory::ECApplication; }

    [[nodiscard]] std::string toString() const override
    {
        return "WindowClosedEvent";
    }

};

class WindowResizedEvent : public Event {
public:
    WindowResizedEvent(unsigned int width, unsigned int height)
            : m_width(width), m_height(height)
    {}

    [[nodiscard]] inline unsigned int getWidth() const
    { return m_width; }

    [[nodiscard]] inline unsigned int getHeight() const
    { return m_height; }

    [[nodiscard]] static EventType getStaticType()
    { return EventType::WindowResized; }

    [[nodiscard]] EventType getType() const override
    { return EventType::WindowResized; }

    [[nodiscard]] int getCategories() const override
    { return EventCategory::ECApplication; }

    [[nodiscard]] std::string toString() const override
    {
        std::stringstream ss;
        ss << "WindowResizedEvent: w:" << m_width << ", h:" << m_height;
        return ss.str();
    }

private:
    unsigned int m_width, m_height;
};

}

#endif //APPLICATION_EVENTS_H
