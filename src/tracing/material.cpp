#include "material.h"

#include <imgui.h>
#include <glm/gtc/type_ptr.hpp>

namespace Trayracer2 {

void Material::showPropertiesUI()
{
    if (ImGui::CollapsingHeader("Material", ImGuiTreeNodeFlags_DefaultOpen)) {
        ImGui::ColorEdit3("Diffuse color", glm::value_ptr(m_diffuseColor));
    }
}

}
