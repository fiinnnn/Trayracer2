#ifndef INPUT_EVENTS_H
#define INPUT_EVENTS_H

#include <string>
#include <sstream>

#include "event.h"

namespace Trayracer2 {

class KeyEvent : public Event {
public:
	[[nodiscard]] inline int getKeyCode() const { return m_keycode; }

	[[nodiscard]] int getCategories() const override { return EventCategory::INPUT | EventCategory::KEYBOARD; }

protected:
	explicit KeyEvent(int keycode)
	    : m_keycode(keycode)
	{}

	int m_keycode;
};

class KeyPressedEvent : public KeyEvent {
public:
	KeyPressedEvent(int keycode, bool repeated)
	    : KeyEvent(keycode), m_repeated(repeated)
	{}

	[[nodiscard]] inline bool getRepeated() const { return m_repeated; }

	[[nodiscard]] static EventType getStaticType() { return EventType::KEY_PRESSED; }
	[[nodiscard]] EventType getType() const override { return EventType::KEY_PRESSED; }

	[[nodiscard]] std::string toString() const override
	{
		std::stringstream ss;
		ss << "KeyPressedEvent: keycode:" << m_keycode << ", repeated:" << m_repeated;
		return ss.str();
	}

private:
	bool m_repeated;
};

class KeyReleasedEvent : public KeyEvent {
public:
	explicit KeyReleasedEvent(int keycode)
			: KeyEvent(keycode)
	{}

	[[nodiscard]] static EventType getStaticType() { return EventType::KEY_RELEASED; }
	[[nodiscard]] EventType getType() const override { return EventType::KEY_RELEASED; }

	[[nodiscard]] std::string toString() const override
	{
		std::stringstream ss;
		ss << "KeyReleasedEvent: keycode:" << m_keycode;
		return ss.str();
	}
};

class KeyTypedEvent : public KeyEvent {
public:
	explicit KeyTypedEvent(int keycode)
			: KeyEvent(keycode)
	{}

	[[nodiscard]] static EventType getStaticType() { return EventType::KEY_TYPED; }
	[[nodiscard]] EventType getType() const override { return EventType::KEY_TYPED; }

	[[nodiscard]] std::string toString() const override
	{
		std::stringstream ss;
		ss << "KeyTypedEvent: keycode:" << m_keycode;
		return ss.str();
	}
};

class MouseButtonEvent : public Event {
public:
	[[nodiscard]] inline int getMouseButton() const { return m_button; }

	[[nodiscard]] int getCategories() const override { return EventCategory::INPUT | EventCategory::MOUSE; }

protected:
	explicit MouseButtonEvent(int button)
	    : m_button(button)
	{}

	int m_button;
};

class MousePressedEvent : public MouseButtonEvent {
public:
	explicit MousePressedEvent(int button)
	    : MouseButtonEvent(button)
	{}

	[[nodiscard]] static EventType getStaticType() { return EventType::MOUSE_PRESSED; }
	[[nodiscard]] EventType getType() const override { return EventType::MOUSE_PRESSED; }

	[[nodiscard]] std::string toString() const override
	{
		std::stringstream ss;
		ss << "MousePressedEvent: button:" << m_button;
		return ss.str();
	}
};

class MouseReleasedEvent : public MouseButtonEvent {
public:
	explicit MouseReleasedEvent(int button)
			: MouseButtonEvent(button)
	{}

	[[nodiscard]] static EventType getStaticType() { return EventType::MOUSE_RELEASED; }
	[[nodiscard]] EventType getType() const override { return EventType::MOUSE_RELEASED; }

	[[nodiscard]] std::string toString() const override
	{
		std::stringstream ss;
		ss << "MouseReleasedEvent: button:" << m_button;
		return ss.str();
	}
};

class MouseMovedEvent : public Event {
public:
	MouseMovedEvent(float x, float y)
	    : m_x(x), m_y(y)
	{}

	[[nodiscard]] inline float getX() const { return m_x; }
	[[nodiscard]] inline float getY() const { return m_y; }

	[[nodiscard]] static EventType getStaticType() { return EventType::MOUSE_MOVED; }
	[[nodiscard]] EventType getType() const override { return EventType::MOUSE_MOVED; }
	[[nodiscard]] int getCategories() const override { return EventCategory::INPUT | EventCategory::MOUSE; }

	[[nodiscard]] std::string toString() const override
	{
		std::stringstream ss;
		ss << "MouseMovedEvent: x:" << m_x << ", y:" << m_y;
		return ss.str();
	}

private:
	float m_x, m_y;
};

class MouseScrolledEvent : public Event {
public:
	MouseScrolledEvent(float offsetX, float offsetY)
	    : m_offsetX(offsetX), m_offsetY(offsetY)
	{}

	[[nodiscard]] inline float getOffsetX() const { return m_offsetX; }
	[[nodiscard]] inline float getOffsetY() const { return m_offsetY; }

	[[nodiscard]] static EventType getStaticType() { return EventType::MOUSE_SCROLLED; }
	[[nodiscard]] EventType getType() const override { return EventType::MOUSE_SCROLLED; }
	[[nodiscard]] int getCategories() const override { return EventCategory::INPUT | EventCategory::MOUSE; }

	[[nodiscard]] std::string toString() const override
	{
		std::stringstream ss;
		ss << "MouseScrolledEvent: x:" << m_offsetX << ", y:" << m_offsetY;
		return ss.str();
	}

private:
	float m_offsetX, m_offsetY;
};

}

#endif //INPUT_EVENTS_H
