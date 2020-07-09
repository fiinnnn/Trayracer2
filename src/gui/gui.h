#ifndef GUI_H
#define GUI_H

#include "tracing/raytracer.h"
#include "scene_ui.h"
#include "metrics_ui.h"

namespace Trayracer2 {

class GUI {
public:
    void show(Raytracer& raytracer);

private:
    SceneUI m_sceneui;
    MetricsUI m_metricsui;
};

}

#endif //GUI_H
