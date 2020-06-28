#ifndef DISPATCHER_H
#define DISPATCHER_H

#include <functional>

namespace Trayracer2 {

#define BIND_EVENT_FN(f) std::bind(&f, this, std::placeholders::_1)

class EventDispatcher {
    template<typename T>
    using EventFn = std::function<bool(T&)>;

public:
    explicit EventDispatcher(Event& e) : m_event(e)
    {}

    template<typename T>
    bool dispatch(EventFn<T> fn)
    {
        if (m_event.getType() == T::getStaticType()) {
            m_event.m_handled = fn(*(T*) &m_event);
            return true;
        }
        return false;
    }

private:
    Event& m_event;
};

}

#endif //DISPATCHER_H
