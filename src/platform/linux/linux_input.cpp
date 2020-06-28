#include "linux_input.h"

#include <GLFW/glfw3.h>

#include "core/application.h"
#include "core/window.h"

namespace Trayracer2 {

Input* Input::m_instance = new LinuxInput();

bool LinuxInput::keyPressedImpl(int keycode)
{
    GLFWwindow* window = static_cast<GLFWwindow*>(Application::get().getWindow().getNativeWindow());

    int state = glfwGetKey(window, keycode);
    return state == GLFW_PRESS || state == GLFW_REPEAT;
}

bool LinuxInput::mousePressedImpl(int button)
{
    GLFWwindow* window = static_cast<GLFWwindow*>(Application::get().getWindow().getNativeWindow());

    int state = glfwGetMouseButton(window, button);
    return state == GLFW_PRESS;
}

std::pair<float, float> LinuxInput::getMousePosImpl()
{
    GLFWwindow* window = static_cast<GLFWwindow*>(Application::get().getWindow().getNativeWindow());

    double xpos, ypos;
    glfwGetCursorPos(window, &xpos, &ypos);
    return {(float) xpos, (float) ypos};
}

}
