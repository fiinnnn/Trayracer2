#ifndef LINUX_INPUT_H
#define LINUX_INPUT_H

#include <utility>

#include "input/input.h"

namespace Trayracer2 {

class LinuxInput : public Input {
protected:
    bool keyPressedImpl(int keycode) override;

    bool mousePressedImpl(int button) override;
    std::pair<float, float> getMousePosImpl() override;
};

}

#endif //LINUX_INPUT_H
