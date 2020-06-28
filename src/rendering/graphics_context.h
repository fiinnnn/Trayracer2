#ifndef GRAPHICS_CONTEXT_H
#define GRAPHICS_CONTEXT_H

namespace Trayracer2 {

class GraphicsContext {
public:
    virtual void init() = 0;
    virtual void swapBuffers() = 0;
};

}

#endif //GRAPHICS_CONTEXT_H
