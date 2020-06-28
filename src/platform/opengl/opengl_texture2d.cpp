#include "opengl_texture2d.h"

#include <glad/glad.h>

namespace Trayracer2 {

OpenGLTexture2D::OpenGLTexture2D(unsigned int width, unsigned int height)
        : Texture2D(width, height)
{
    glCreateTextures(GL_TEXTURE_2D, 1, &m_id);
    glTextureStorage2D(m_id, 1, GL_RGB32F, m_width, m_height);

    glTextureParameteri(m_id, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTextureParameteri(m_id, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
}

OpenGLTexture2D::~OpenGLTexture2D()
{
    glDeleteTextures(1, &m_id);
}

void OpenGLTexture2D::update(void* buffer)
{
    glTextureSubImage2D(m_id, 0, 0, 0, m_width, m_height, GL_RGB, GL_FLOAT,
                        buffer);
}

}
