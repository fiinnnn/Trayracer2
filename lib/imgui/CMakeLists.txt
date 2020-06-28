project(imgui)

list(APPEND IMGUI_PUBLIC_HEADERS
        "imgui/imgui.h")

list(APPEND IMGUI_PRIVATE_HEADERS
        "imgui/imgui_internal.h"
        "imgui/imconfig.h"
        "imgui/stb_rect_pack.h"
        "imgui/stb_textedit.h"
        "imgui/stb_truetype.h")

list(APPEND IMGUI_SOURCES
        "imgui/imgui.cpp"
        "imgui/imgui_draw.cpp"
        "imgui/imgui_demo.cpp"
        "imgui/imgui_widgets.cpp")

list(APPEND IMGUI_PUBLIC_INCLUDE_DIRS
        imgui)

add_library(${PROJECT_NAME} STATIC ${IMGUI_SOURCES})
target_link_libraries(${PROJECT_NAME} PUBLIC ${IMGUI_PUBLIC_LIBRARIES})
target_include_directories(${PROJECT_NAME}
        PUBLIC ${IMGUI_PUBLIC_INCLUDE_DIRS}
        PRIVATE ${IMGUI_PRIVATE_INCLUDE_DIRS})
