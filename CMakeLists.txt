cmake_minimum_required(VERSION 3.19)
project(retrodl8 CXX)

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
        src/core/asset_manager.cpp
        src/components/SpriteComponent.cpp src/core/Engine.cpp src/core/Engine.h src/constants.h)
add_executable(${PROJECT_NAME} ${SOURCE})


add_subdirectory(thirdparty/jansson EXCLUDE_FROM_ALL)
target_link_libraries(${PROJECT_NAME} PRIVATE jansson)

add_subdirectory(thirdparty/lua EXCLUDE_FROM_ALL)
target_link_libraries(${PROJECT_NAME} PRIVATE lua )
target_link_libraries(${PROJECT_NAME} PRIVATE SDL2)
target_link_libraries(${PROJECT_NAME} PRIVATE SDL2_image)
target_link_libraries(${PROJECT_NAME} PRIVATE SDL2_ttf)
target_link_libraries(${PROJECT_NAME} PRIVATE SDL2_mixer)
add_subdirectory(thirdparty/doctest EXCLUDE_FROM_ALL)
target_link_libraries(${PROJECT_NAME} PRIVATE doctest)
add_subdirectory(thirdparty/glm EXCLUDE_FROM_ALL)
include_directories(thirdparty/glm/glm)
target_link_libraries(${PROJECT_NAME} PRIVATE glm )

# copy assets folder to the target build folder
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                        COMMAND ${CMAKE_COMMAND} -E copy_directory
                        ${CMAKE_SOURCE_DIR}/assets $<TARGET_FILE_DIR:${PROJECT_NAME}>/assets)