cmake_minimum_required(VERSION 3.19)
project(lua)

set(CMAKE_CXX_STANDARD 14)

set(LUA_SOURCE
        src/lapi.c
        src/lauxlib.c
        src/lbaselib.c
        src/lcode.c
        src/lcorolib.c
        src/lctype.c
        src/ldblib.c
        src/ldebug.c
        src/ldo.c
        src/ldump.c
        src/lfunc.c
        src/lgc.c
        src/linit.c
        src/liolib.c
        src/llex.c
        src/lmathlib.c
        src/lmem.c
        src/loadlib.c
        src/lobject.c
        src/lopcodes.c
        src/loslib.c
        src/lparser.c
        src/lstate.c
        src/lstring.c
        src/lstrlib.c
        src/ltable.c
        src/ltablib.c
        src/ltm.c
        src/lua.c
        src/luac.c
        src/lundump.c
        src/lutf8lib.c
        src/lvm.c
        src/lzio.c
        )
add_library(${PROJECT_NAME} ${LUA_SOURCE})
target_include_directories(${PROJECT_NAME} PUBLIC)