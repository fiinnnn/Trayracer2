#ifndef EVENT_H
#define EVENT_H

#include <string>
#include <ostream>

namespace Trayracer2 {

enum class EventType {
	NONE,
	WINDOW_CLOSED,
	WINDOW_RESIZED,
	KEY_PRESSED,
	KEY_RELEASED,
	KEY_TYPED,
	MOUSE_PRESSED,
	MOUSE_RELEASED,
	MOUSE_MOVED,
	MOUSE_SCROLLED
};

enum EventCategory {
	NONE,
	APPLICATION = (1 << 0),
	INPUT       = (1 << 1),
	KEYBOARD    = (1 << 2),
	MOUSE       = (1 << 3)
};



class Event {
	friend class EventDispatcher;

public:
	virtual ~Event() = default;

	[[nodiscard]] virtual EventType getType() const = 0;
	[[nodiscard]] virtual int getCategories() const = 0;

	[[nodiscard]] virtual std::string toString() const = 0;

	[[nodiscard]] inline bool handled() const { return m_handled; }

protected:
	bool m_handled = false;
};

inline std::ostream& operator<<(std::ostream& os, const Event& e)
{
	return os << e.toString();
}

}

#endif //EVENT_H
