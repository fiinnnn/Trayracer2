project(MetricsGui)

list(APPEND METRICSGUI_SOURCES
        "metrics_gui/source/metrics_gui.cpp")

add_library(${PROJECT_NAME} STATIC "${METRICSGUI_SOURCES}")
target_link_libraries(${PROJECT_NAME} imgui)
target_include_directories(${PROJECT_NAME}
        PUBLIC metrics_gui/include/metrics_gui
        PRIVATE lib/imgui)
