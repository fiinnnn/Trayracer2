#ifndef APPLICATION_H
#define APPLICATION_H

#include <memory>

#include "core.h"
#include "window.h"

namespace Trayracer2 {

class Application {
public:
	Application();
	virtual ~Application();

	void run();

private:
	static Application* m_instance;

	bool m_running = true;

	std::unique_ptr<Window> m_window;
};

}

#endif //APPLICATION_H
