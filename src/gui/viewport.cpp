#include "viewport.h"

#include <imgui.h>

namespace Trayracer2 {

void Viewport::show(Raytracer& raytracer)
{
    ImGui::Begin("Viewport", nullptr, ImGuiWindowFlags_NoScrollWithMouse);
    if ((float) raytracer.getWidth() != ImGui::GetWindowWidth() ||
        (float) raytracer.getHeight() != ImGui::GetWindowHeight()) {
        raytracer.resize((unsigned int) ImGui::GetWindowWidth(),
                         (unsigned int) ImGui::GetWindowHeight());
    }
    ImGui::Image((void*) raytracer.getRenderTargetID(),
                 ImGui::GetContentRegionAvail());
    ImGui::End();
}

}
