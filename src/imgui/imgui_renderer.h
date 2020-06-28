#ifndef IMGUI_RENDERER_H
#define IMGUI_RENDERER_H


namespace Trayracer2 {

class ImGuiRenderer {
public:
    ImGuiRenderer();
    ~ImGuiRenderer();

    static void begin();
    static void end();
};

}

#endif //IMGUI_RENDERER_H
