#ifndef VIEWPORT_H
#define VIEWPORT_H

#include <string>
#include <imgui.h>

#include "tracing/raytracer.h"

namespace Trayracer2 {

class Viewport {
public:
    Viewport()
    {
        m_size.x = -1;
        m_size.y = -1;
    }

    void show(const std::string& title, Raytracer& raytracer);

private:
    ImVec2 m_size;
};

}

#endif //VIEWPORT_H
