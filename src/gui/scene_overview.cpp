#include "scene_overview.h"

#include <imgui.h>

#include "core/core.h"
#include "tracing/scene.h"

namespace Trayracer2 {

void SceneOverview::show(Ref<Scene> scene)
{
    ImGui::Begin("Scene");

    ImGui::Button("Add object");
    ImGui::Separator();

    if (ImGui::TreeNode("Obj 1")) {
        if (ImGui::TreeNode("Obj 2")) {
            ImGui::TreePop();
        }
        if (ImGui::TreeNode("Obj 3")) {
            ImGui::TreePop();
        }
        ImGui::TreePop();
    }
    if (ImGui::TreeNode("Obj 4")) {
        ImGui::TreePop();
    }

    ImGui::End();
}

}
