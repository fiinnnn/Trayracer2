#include "sphere.h"

namespace Trayracer2 {

Intersection Sphere::intersect(const Ray &ray) const
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

}
