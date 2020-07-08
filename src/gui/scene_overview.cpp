#include "scene_overview.h"

#include <imgui.h>

#include "core/core.h"
#include "tracing/scene.h"
#include "tracing/objects/scene_object.h"

namespace Trayracer2 {

void SceneOverview::show(Ref<Scene> scene)
{
    ImGui::Begin("Scene");

    if (ImGui::BeginPopupContextWindow()) {
        if (ImGui::MenuItem("Add sphere")) {
        }
        ImGui::Separator();
        if (ImGui::MenuItem("Add mesh")) {
        }
        ImGui::EndPopup();
    }

    for (auto& obj : scene->getObjects()) {
        ImGui::Selectable(obj->getName().c_str());
    }

    ImGui::End();
}

}
