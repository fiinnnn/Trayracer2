#ifndef LINUX_WINDOW_H
#define LINUX_WINDOW_H

#include <string>
#include <GLFW/glfw3.h>

#include "window.h"

namespace Trayracer2 {

class LinuxWindow : public Window {
public:
	LinuxWindow(const WindowCfg& cfg);
	virtual ~LinuxWindow();

	void update() override;

	inline unsigned int getWidth() const override { return m_data.width; }
	inline unsigned int getHeight() const override { return m_data.height; }

	inline void setVsync(bool enabled) override;
	inline bool getVsync() const override { return m_data.vsync; }

private:
	void init(const WindowCfg& cfg);
	void close();

	GLFWwindow* m_window;

	struct WindowData {
		std::string title;
		unsigned int width, height;
		bool vsync;
	};

	WindowData m_data;
};

}

#endif //LINUX_WINDOW_H
