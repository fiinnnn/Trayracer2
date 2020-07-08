project(imgui)

list(APPEND IMGUI_SOURCES
        "imgui/imgui.cpp"
        "imgui/imgui_draw.cpp"
        "imgui/imgui_demo.cpp"
        "imgui/imgui_widgets.cpp")

list(APPEND IMGUI_PUBLIC_INCLUDE_DIRS
        imgui)

add_library(${PROJECT_NAME} STATIC ${IMGUI_SOURCES})
target_include_directories(${PROJECT_NAME}
        PUBLIC ${IMGUI_PUBLIC_INCLUDE_DIRS})
