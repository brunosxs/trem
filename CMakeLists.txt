cmake_minimum_required(VERSION 3.19)
project(retrodl8)

set(CMAKE_CXX_STANDARD 14)
include_directories(libs/lua)
include_directories(libs/glm)
set(SOURCE
        src/core/entity.cpp
        src/core/entity_manager.cpp
        src/components/transform.cpp
        src/game.cpp
        src/main.cpp
        )
add_executable(${PROJECT_NAME} ${SOURCE})
target_link_libraries(${PROJECT_NAME} lua )
target_link_libraries(${PROJECT_NAME} SDL2)
target_link_libraries(${PROJECT_NAME} SDL2_image)
target_link_libraries(${PROJECT_NAME} SDL2_ttf)
target_link_libraries(${PROJECT_NAME} SDL2_mixer)