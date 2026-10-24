
cmake_minimum_required(VERSION 3.21)

project(OpenGLWorkshop
    VERSION 0.1.0
    LANGUAGES C CXX
)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)

# SDL3
set(SDL_SHARED ON CACHE BOOL "" FORCE)
set(SDL_STATIC OFF CACHE BOOL "" FORCE)

FetchContent_Declare(
    SDL3
    GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
    GIT_TAG release-3.4.16
    GIT_SHALLOW TRUE
)

# GLM
FetchContent_Declare(
    glm
    GIT_REPOSITORY https://github.com/g-truc/glm.git
    GIT_TAG 1.0.3
    GIT_SHALLOW TRUE
)

FetchContent_MakeAvailable(SDL3 glm)

add_library(glad STATIC
    3rdParty/glad/src/glad.c
)

target_include_directories(glad PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/3rdParty/glad/include"
)

add_executable(opengl-workshop
    src/main.cpp
    src/Window.cpp
    src/Renderer.cpp
    src/Files.cpp
    exercises/exo1.h
    exercises/exercise.h
    exercises/exo2.h
    exercises/exo3.h
    exercises/exo4.h    exercises/exo5.h
    reference-solutions/exercises/exo1.h
    reference-solutions/exercises/exo2.h
    reference-solutions/exercises/exo3.h
    reference-solutions/exercises/exo4.h
    reference-solutions/exercises/exo5.h
    reference-solutions/exercises/reference_helpers.h
)

target_include_directories(opengl-workshop PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}"
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
    "${CMAKE_CURRENT_SOURCE_DIR}/3rdParty/stb"
    "${CMAKE_CURRENT_SOURCE_DIR}/exercises"
    "${CMAKE_CURRENT_SOURCE_DIR}/reference-solutions/exercises"
)

target_link_libraries(opengl-workshop PRIVATE
    SDL3::SDL3
    glad
    glm::glm
)

target_compile_options(opengl-workshop PRIVATE
    $<$<COMPILE_LANGUAGE:CXX>:$<$<CXX_COMPILER_ID:GNU,Clang>:-Wall;-Wextra;-Wpedantic>>
)