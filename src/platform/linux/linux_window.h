#ifndef LINUX_WINDOW_H
#define LINUX_WINDOW_H

#include <string>
#include <GLFW/glfw3.h>

#include "core/window.h"

namespace Trayracer2 {

class GraphicsContext;

class LinuxWindow : public Window {
public:
	explicit LinuxWindow(const WindowCfg& cfg);
	~LinuxWindow() override;

	void update() override;

	[[nodiscard]] inline unsigned int getWidth() const override { return m_data.width; }
	[[nodiscard]] inline unsigned int getHeight() const override { return m_data.height; }

	inline void setVsync(bool enabled) override;
	[[nodiscard]] inline bool getVsync() const override { return m_data.vsync; }

	inline void setEventCallback(const EventCallback& callback) override { m_data.eventCallback = callback; }

	[[nodiscard]] inline void* getNativeWindow() const override { return m_window; }

private:
	void init(const WindowCfg& cfg);
	void close();

private:
	GLFWwindow* m_window;
	GraphicsContext* m_context;

	struct WindowData {
		std::string title;
		unsigned int width, height;
		bool vsync;

		EventCallback eventCallback;
	};

	WindowData m_data;
};

}

#endif //LINUX_WINDOW_H
