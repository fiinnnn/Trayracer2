#ifndef SCENE_UI_H
#define SCENE_UI_H

#include "core/core.h"
#include "tracing/scene.h"

namespace Trayracer2 {

class SceneUI {
public:
    void show(const Ref<Scene>& scene);

private:
    void showOverview(const Ref<Scene>& scene);

    void showProperties(const Ref<Scene>& scene);

private:
    Ref<SceneObject> m_selected;
};

}

#endif //SCENE_UI_H
