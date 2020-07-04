#include "raytracer.h"

#include <glm/glm.hpp>

#include "rendering/texture2d.h"

namespace Trayracer2 {

float intersectSphere(Ray r, Sphere s)
{
    glm::vec3 oc = r.origin - s.position;
    float p = -dot(r.dir, oc);
    float d = p * p - dot(oc, oc) + s.r * s.r;
    if (d < 0) return 48000;
    else if (d == 0) return (p < 0) ? 480000 : p;
    else {
        float t1 = std::sqrt(d);
        float t2 = p + t1;
        t1 = p - t1;

        if (t1 < -0.001 || t2 < -0.001) return 48000;
        if (fminf(t1, t2) < 0.001) return 48000;
        return fminf(t1,t2);
    }
}

Raytracer::Raytracer()
{
    m_renderTarget = Texture2D::create(512, 512);
    m_buffer = (Color*)malloc(512 * 512 * sizeof(Color));

    m_scene = createRef<Scene>();
}

void Raytracer::trace()
{
    unsigned int width = m_renderTarget->getWidth();
    unsigned int height = m_renderTarget->getHeight();

    glm::vec3 c = glm::vec3(0,0,-1);
    glm::vec3 u = glm::vec3(0,1,0);
    glm::vec3 r = glm::vec3(1,0,0);

    glm::vec3 p0 = c - u - r;
    glm::vec3 p1 = c - u + r;
    glm::vec3 p2 = c + u - r;

    glm::vec3 p0p1 = p1 - p0;
    glm::vec3 p0p2 = p2 - p0;

    Sphere s = Sphere(glm::vec3(0,0,-2), 1.0f);

    float aspectRatio = (float)width / (float)height;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            float rX = ((((float)x + 0.5f) / (float)width) * 2.0f - 1.0f) * aspectRatio;
            float rY = 1.0f - (((float)y + 0.5) / (float)height) * 2.0f;
            glm::vec3 dir = glm::normalize(glm::vec3(rX, rY, -1.0));
            Ray ray = Ray(glm::vec3(0,0,0), dir);

            if (intersectSphere(ray, s) < 48000)
                m_buffer[x+y*width] = Color(1.0, 0, 0);
            else
                m_buffer[x+y*width] = Color(0, 0, 0);
        }
    }

    m_renderTarget->update((void*) m_buffer);
}

void Raytracer::resize(unsigned int width, unsigned int height)
{
    m_renderTarget->resize(width, height);
    m_buffer = (Color*)realloc(m_buffer, width * height * sizeof(Color));
}

}
