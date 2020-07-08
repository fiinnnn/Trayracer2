#include "raytracer.h"

#include <glm/glm.hpp>

#include "rendering/texture2d.h"

namespace Trayracer2 {

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

    float aspectRatio = (float)width / (float)height;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            float rX = ((((float)x + 0.5f) / (float)width) * 2.0f - 1.0f) * aspectRatio;
            float rY = 1.0f - (((float)y + 0.5f) / (float)height) * 2.0f;
            glm::vec3 dir = glm::normalize(glm::vec3(rX, rY, -1.0));
            Ray ray = Ray(glm::vec3(0,0,0), dir);

            auto i = m_scene->intersect(ray);

            if (i.hit)
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
