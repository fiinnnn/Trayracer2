project(glad)

get_filename_component(THIRD_PARTY_DIR ${CMAKE_CURRENT_SOURCE_DIR} DIRECTORY)
set(GLAD_SRC_DIR ${THIRD_PARTY_DIR}/glad)

list(APPEND GLAD_SOURCES ${GLAD_SRC_DIR}/src/glad.c)

list(APPEND GLAD_INCLUDE_DIRS ${GLAD_SRC_DIR}/include)

list(APPEND GLAD_LIBRARIES dl)

add_library(${PROJECT_NAME} STATIC ${GLAD_SOURCES})
target_link_libraries(${PROJECT_NAME} ${GLAD_LIBRARIES})
target_include_directories(${PROJECT_NAME} PUBLIC ${GLAD_INCLUDE_DIRS})
