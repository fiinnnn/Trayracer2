#include "menu_bar.h"

#include <imgui.h>

namespace Trayracer2 {

void MenuBar::show()
{
    if (ImGui::BeginMainMenuBar()) {
        if (ImGui::BeginMenu("File")) {
            ImGui::MenuItem("Load Scene");
            ImGui::EndMenu();
        }
        ImGui::EndMainMenuBar();
    }
}

}
