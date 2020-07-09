#include "scene_ui.h"

#include <imgui.h>

#include "core/core.h"
#include "tracing/scene.h"
#include "tracing/objects/scene_object.h"
#include "tracing/objects/sphere.h"

namespace Trayracer2 {

void SceneUI::show(const Ref<Scene>& scene)
{
    showOverview(scene);
    showProperties(scene);
}

void SceneUI::showOverview(const Ref<Scene>& scene)
{
    ImGui::Begin("Scene");

    if (ImGui::BeginPopupContextWindow()) {
        if (ImGui::MenuItem("Add sphere")) {
            scene->addObject(createRef<Sphere>());
        }
        ImGui::EndPopup();
    }

    for (auto& obj : scene->getObjects()) {
        ImGui::PushID(obj.get());
        if (ImGui::Selectable(obj->getName().c_str(), obj == m_selected)) {
            m_selected = obj;
        }
        ImGui::PopID();
    }

    ImGui::End();
}

void SceneUI::showProperties(const Ref<Scene>& scene)
{
    ImGui::Begin("Properties");

    if (m_selected != nullptr) {
        m_selected->showPropertiesUI();

        ImGui::Separator();
        if (ImGui::Button("Delete")) {
            scene->removeObject(m_selected);
            m_selected = nullptr;
        }
    }

    ImGui::End();
}

}
