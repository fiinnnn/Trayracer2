cmake_minimum_required(VERSION 3.16)
project(trayracer2)

find_program(CONAN conan)
if (NOT CONAN)
	message(FATAL_ERROR "Needs conan package manager: please visit https://conan.io and install")
endif()

include(${CMAKE_SOURCE_DIR}/cmake/conan.cmake)

conan_check()

conan_cmake_run(CONANFILE conanfile.txt
		BASIC_SETUP CMAKE_TARGETS
		BUILD missing)

find_package(glfw3 REQUIRED)
find_package(glm REQUIRED)

set(CMAKE_CXX_STANDARD 17)
add_compile_options("-Wall"
		"$<$<CONFIG:DEBUG>:-O0;-g>"
		"$<$<CONFIG:RELEASE>:-O3>")

add_subdirectory(lib)
add_subdirectory(src)
