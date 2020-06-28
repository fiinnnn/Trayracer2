#ifndef OPENGL_TEXTURE2D_H
#define OPENGL_TEXTURE2D_H

#include "rendering/texture2d.h"

namespace Trayracer2 {

class OpenGLTexture2D : public Texture2D {
public:
    OpenGLTexture2D(unsigned int width, unsigned int height);
    ~OpenGLTexture2D() override;

    [[nodiscard]] unsigned int getID() const override
    { return m_id; }

    void update(void* buffer) override;

private:
    unsigned int m_id = 0;
};

}

#endif //OPENGL_TEXTURE2D_H
