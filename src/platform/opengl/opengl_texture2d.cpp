#include "opengl_texture2d.h"

#include <glad/glad.h>

namespace Trayracer2 {

OpenGLTexture2D::OpenGLTexture2D(unsigned int width, unsigned int height)
        : Texture2D(width, height)
{
    glCreateTextures(GL_TEXTURE_2D, 1, &m_id);
    glBindTexture(GL_TEXTURE_2D, m_id);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB32F, width, height, 0, GL_RGB, GL_FLOAT, NULL);

    glTextureParameteri(m_id, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTextureParameteri(m_id, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glBindTexture(GL_TEXTURE_2D, 0);
}

OpenGLTexture2D::~OpenGLTexture2D()
{
    glDeleteTextures(1, &m_id);
}

void OpenGLTexture2D::update(void* buffer)
{
    glBindTexture(GL_TEXTURE_2D, m_id);
    glTextureSubImage2D(m_id, 0, 0, 0, m_width, m_height, GL_RGB, GL_FLOAT,
                        buffer);
    glBindTexture(GL_TEXTURE_2D, 0);
}

void OpenGLTexture2D::resize(unsigned int width, unsigned int height)
{
    m_width = width;
    m_height = height;
    glBindTexture(GL_TEXTURE_2D, m_id);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB32F, width, height, 0, GL_RGB, GL_FLOAT, nullptr);
    glBindTexture(GL_TEXTURE_2D, 0);
}

}
