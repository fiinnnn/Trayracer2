#include "viewport.h"

#include <imgui.h>

namespace Trayracer2 {

void Viewport::show(const std::string& title, Raytracer& raytracer)
{
    ImGui::Begin(title.c_str(), nullptr, ImGuiWindowFlags_NoScrollWithMouse);
    if (ImGui::GetWindowWidth() != m_size.x || ImGui::GetWindowHeight() != m_size.y) {
        m_size.x = ImGui::GetWindowWidth();
        m_size.y = ImGui::GetWindowHeight();
        raytracer.resize((unsigned int) m_size.x, (unsigned int) m_size.y);
    }
    ImGui::Image((void*) raytracer.getRenderTargetID(), ImGui::GetContentRegionAvail());
    ImGui::End();
}

}
