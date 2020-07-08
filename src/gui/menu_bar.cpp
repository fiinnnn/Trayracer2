#include "menu_bar.h"

#include <imgui.h>

#include "core/application.h"

namespace Trayracer2 {

void MenuBar::show()
{
    if (ImGui::BeginMainMenuBar()) {
        if (ImGui::BeginMenu("File")) {

            ImGui::MenuItem("Load Scene");

            ImGui::Separator();

            if (ImGui::MenuItem("Exit")) {
                Application::get().exit();
            }

            ImGui::EndMenu();
        }
        ImGui::EndMainMenuBar();
    }
}

}
