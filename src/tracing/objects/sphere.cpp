#include "sphere.h"

#include <imgui.h>
#include <glm/gtc/type_ptr.hpp>

namespace Trayracer2 {

Intersection Sphere::intersect(const Ray &ray)
{
    Intersection i(false, 1000000, nullptr); //TODO: set far clip dist

    glm::vec3 oc = ray.origin - m_pos;
    float p = -dot(ray.dir, oc);
    float d = p * p - dot(oc, oc) + m_r * m_r;
    if (d < 0) return i;
    else if (d == 0) {
        if (p < 0) return i;
        else {
            i.hit = true;
            i.dist = p;
            i.object = this;
            return i;
        }
    }
    else {
        float t1 = std::sqrt(d);
        float t2 = p + t1;
        t1 = p - t1;

        if (t1 < -0.001 || t2 < -0.001) return i;
        if (fminf(t1, t2) < 0.001) return i;
        i.hit = true;
        i.dist = fminf(t1, t2);
        i.object = this;
        return i;
    }
}

void Sphere::showPropertiesUI()
{
    ImGui::Text("%s", getName().c_str());
    ImGui::SameLine();
    ImGui::TextColored(ImVec4(0.5f, 0.5f, 0.5f, 1.0f),"(%s)", getTypeName().c_str());

    ImGui::Separator();

    if (ImGui::CollapsingHeader("Sphere", ImGuiTreeNodeFlags_DefaultOpen)) {
        ImGui::InputFloat3("Position", glm::value_ptr(m_pos));
        ImGui::InputFloat("Radius", &m_r, 0.1f);
    }

    getMaterial().showPropertiesUI();
}

}
