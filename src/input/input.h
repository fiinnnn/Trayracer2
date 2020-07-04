#ifndef INPUT_H
#define INPUT_H

#include <utility>

#include "keycodes.h"
#include "buttoncodes.h"

namespace Trayracer2 {

class Input {
public:
    [[nodiscard]] inline static bool keyPressed(int keycode)
    { return m_instance->keyPressedImpl(keycode); }

    [[nodiscard]] inline static bool mousePressed(int button)
    { return m_instance->mousePressedImpl(button); }

    [[nodiscard]] inline static std::pair<float, float> getMousePos()
    { return m_instance->getMousePosImpl(); }

protected:
    virtual bool keyPressedImpl(int keycode) = 0;

    virtual bool mousePressedImpl(int button) = 0;

    virtual std::pair<float, float> getMousePosImpl() = 0;

private:
    static Input* m_instance;
};

}

#endif //INPUT_H
