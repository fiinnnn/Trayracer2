project(trayracer2)

set(TRAYRACER2_SOURCES main.cpp log.cpp application.cpp
		platform/linux/linux_window.cpp
		platform/opengl/opengl_context.cpp)

set(TRAYRACER2_LIBRARIES
		glad
		glfw
		imgui
		CONAN_PKG::spdlog)

add_executable(${PROJECT_NAME} ${TRAYRACER2_SOURCES})
target_link_libraries(${PROJECT_NAME} ${TRAYRACER2_LIBRARIES})
target_include_directories(${PROJECT_NAME} PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR}
		lib/glad/include
		lib/imgui)
target_compile_definitions(${PROJECT_NAME} PRIVATE GLFW_INCLUDE_NONE)
