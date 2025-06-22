# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

set(CMAKE_CXX_STANDARD 17)

project ("d3d_tutorial")

add_executable(d3d_tutorial main.cpp)

set_target_properties(d3d_tutorial PROPERTIES
    LINK_FLAGS "/SUBSYSTEM:WINDOWS"
)


target_link_libraries(d3d_tutorial
    d3d12.lib
    dxgi.lib
    d3dcompiler.lib
    dxguid.lib
)
