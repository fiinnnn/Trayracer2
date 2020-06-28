#include "viewport.h"

#include <imgui.h>

namespace Trayracer2 {

void Viewport::show(const std::string& title, unsigned int textureID)
{
    ImGui::Begin(title.c_str(), nullptr, ImGuiWindowFlags_NoScrollWithMouse);
    ImGui::Image((void*) textureID, ImGui::GetContentRegionAvail());
    ImGui::End();
}

}
