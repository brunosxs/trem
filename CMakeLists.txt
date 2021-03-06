cmake_minimum_required(VERSION 3.19)
project(trem CXX)

set(CMAKE_CXX_STANDARD 14)
option(RETRODL8_UNITY_TESTS "Start unity tests" OFF )
set(JANSSON_BUILD_DOCS OFF CACHE BOOL "do not build documentation for JANSSON" FORCE)
set(RETRODL8_UNITY_TESTS ON)

set(TREM_SOURCE
        src/main.cpp
        src/core/color.cpp
        src/core/color.h
        src/core/screenBuffer.h
        src/core/screenBuffer.cpp
        src/core/screen.h
        src/core/screen.cpp
        src/utils/utils.cpp
        src/utils/utils.h
        src/utils/vector2d.cpp
        src/utils/vector2d.h
        src/core/shapes/line2d.h
        src/core/shapes/line2d.cpp

        )
add_executable( ${PROJECT_NAME} ${TREM_SOURCE} )
target_include_directories(${PROJECT_NAME} BEFORE PUBLIC "src")

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
target_include_directories(${PROJECT_NAME} BEFORE PRIVATE thirdparty/lua)
target_include_directories(${PROJECT_NAME} BEFORE PRIVATE thirdparty/glm)
target_include_directories(${PROJECT_NAME} BEFORE PRIVATE thirdparty/glm/glm)
target_link_libraries(${PROJECT_NAME} PRIVATE glm )

# copy assets folder to the target build folder
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                        COMMAND ${CMAKE_COMMAND} -E copy_directory
                        ${CMAKE_SOURCE_DIR}/assets $<TARGET_FILE_DIR:${PROJECT_NAME}>/assets)
