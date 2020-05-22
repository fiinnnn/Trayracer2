#ifndef WINDOW_H
#define WINDOW_H

#include <string>

#include "core.h"

namespace Trayracer2 {

struct WindowCfg {
	std::string title;
	unsigned int width, height;

	WindowCfg(const std::string& windowtitle = "Trayracer2",
			unsigned int w = 1280,
			unsigned int h = 720)
			: title(windowtitle), width(w), height(h)
			{}
};

class Window {
public:
	static Window* create(const WindowCfg& cfg = WindowCfg());

	virtual ~Window() {};

	virtual void update() = 0;

	virtual unsigned int getWidth() const = 0;
	virtual unsigned int getHeight() const = 0;

	virtual void setVsync(bool enabled) = 0;
	virtual bool getVsync() const = 0;
};

}

#endif //WINDOW_H
