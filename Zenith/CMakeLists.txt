cmake_minimum_required(VERSION 3.16)
project(ZenithEngine)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_TOOLCHAIN_FILE "path/to/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")

add_executable(ZenithEngine
    main.cpp
    Graphics/GraphicsEngine.cpp
    Graphics/GraphicsEngine.h
)

find_package(glfw3 CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)

target_link_libraries(ZenithEngine PRIVATE glfw glad glm::glm)
