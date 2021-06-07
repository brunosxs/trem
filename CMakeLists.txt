cmake_minimum_required(VERSION 3.19)
project(retrodl8)

set(CMAKE_CXX_STANDARD 14)
include_directories(thirdparty/lua)
include_directories(thirdparty/glm)
option(RETRODL8_UNITY_TESTS "Start unity tests" OFF )
set(JANSSON_BUILD_DOCS OFF CACHE BOOL "do not build documentation for JANSSON" FORCE)
set(RETRODL8_UNITY_TESTS ON)

set(SOURCE
        src/core/entity.cpp
        src/core/entity_manager.cpp
        src/core/texture_manager.cpp
        src/components/transform.cpp
        src/game.cpp
        src/main.cpp
        )
add_executable(${PROJECT_NAME} ${SOURCE})
add_subdirectory(thirdparty/jansson)
add_subdirectory(thirdparty/doctest)
add_subdirectory(thirdparty/lua)
add_subdirectory(thirdparty/glm)

find_package(glm REQUIRED)
target_link_libraries(${PROJECT_NAME} jansson)
target_link_libraries(${PROJECT_NAME} lua )
target_link_libraries(${PROJECT_NAME} glm )
target_link_libraries(${PROJECT_NAME} SDL2)
target_link_libraries(${PROJECT_NAME} SDL2_image)
target_link_libraries(${PROJECT_NAME} SDL2_ttf)
target_link_libraries(${PROJECT_NAME} SDL2_mixer)
target_link_libraries(${PROJECT_NAME} doctest)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                        COMMAND ${CMAKE_COMMAND} -E copy_directory
                        ${CMAKE_SOURCE_DIR}/assets $<TARGET_FILE_DIR:${PROJECT_NAME}>/assets)