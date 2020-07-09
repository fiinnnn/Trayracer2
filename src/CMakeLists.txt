project(trayracer2)

set(TRAYRACER2_SOURCES
        core/main.cpp
        core/log.cpp
        core/application.cpp
        gui/gui.cpp
        gui/viewport.cpp
        gui/dockspace.cpp
        gui/scene_ui.cpp
        gui/settings_ui.cpp
        gui/menu_bar.cpp
        gui/metrics_ui.cpp
        imgui/imgui.cpp
        imgui/imgui_renderer.cpp
        rendering/renderer_api.cpp
        rendering/render_command.cpp
        rendering/texture2d.cpp
        tracing/raytracer.cpp
        tracing/scene.cpp
        tracing/objects/sphere.cpp
        platform/linux/linux_window.cpp
        platform/linux/linux_input.cpp
        platform/opengl/opengl_context.cpp
        platform/opengl/opengl_renderer_api.cpp
        platform/opengl/opengl_texture2d.cpp)

set(TRAYRACER2_LIBRARIES
        glad
        glfw
        imgui
        MetricsGui
        CONAN_PKG::spdlog)

add_executable(${PROJECT_NAME} ${TRAYRACER2_SOURCES})
target_link_libraries(${PROJECT_NAME} ${TRAYRACER2_LIBRARIES})
target_include_directories(${PROJECT_NAME} PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        lib/glad/include
        lib/imgui
        lib/MetricsGui)
target_compile_definitions(${PROJECT_NAME} PRIVATE GLFW_INCLUDE_NONE)
