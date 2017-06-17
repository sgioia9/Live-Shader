cmake_minimum_required(VERSION 3.0)
project(SGraphic)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
if (WIN32)
  set(CMAKE_PREFIX_PATH "C:/Qt/5.9/mingw53_32/lib/cmake/Qt5Widgets")
else()
  set(CMAKE_PREFIX_PATH "/home/stefano/Qt/5.9/gcc_64/lib/cmake/Qt5Widgets")
endif()

find_package(Qt5Widgets REQUIRED)

option(GLFW_BUILD_DOCS OFF)
option(GLFW_BUILD_EXAMPLES OFF)
option(GLFW_BUILD_TESTS OFF)
add_subdirectory(SGraphic/Vendor/glfw)

option(ASSIMP_BUILD_ASSIMP_TOOLS OFF)
option(ASSIMP_BUILD_SAMPLES OFF)
option(ASSIMP_BUILD_TESTS OFF)
add_subdirectory(SGraphic/Vendor/assimp)

option(BUILD_BULLET2_DEMOS OFF)
option(BUILD_CPU_DEMOS OFF)
option(BUILD_EXTRAS OFF)
option(BUILD_OPENGL3_DEMOS OFF)
option(BUILD_UNIT_TESTS OFF)
add_subdirectory(SGraphic/Vendor/bullet)

add_subdirectory(SGraphic/Vendor/SOIL)

if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -std=c++11")
    if(NOT WIN32)
        set(GLAD_LIBRARIES dl)
    endif()
endif()

include_directories(
  SGraphic/Headers/
  SGraphic/Vendor/assimp/include/
  SGraphic/Vendor/bullet/src/
  SGraphic/Vendor/glfw/include/
  SGraphic/Vendor/glm/
  SGraphic/Vendor/SOIL/src)

file(GLOB PROJECT_HEADERS SGraphic/Headers/*.hpp)
file(GLOB PROJECT_SOURCES SGraphic/Sources/*.cpp)
file(GLOB PROJECT_SHADERS 
  SGraphic/Shaders/*.comp
  SGraphic/Shaders/*.frag
  SGraphic/Shaders/*.geom
  SGraphic/Shaders/*.vert)
file(GLOB PROJECT_CONFIGS CMakeLists.txt
                          Readme.md
                         .gitattributes
                         .gitignore
                         .gitmodules)

source_group("Headers" FILES ${PROJECT_HEADERS})
source_group("Shaders" FILES ${PROJECT_SHADERS})
source_group("Sources" FILES ${PROJECT_SOURCES})
source_group("Vendors" FILES ${VENDORS_SOURCES})

set(PROJECT_SHADERS_DIR "SGraphic/Shaders/")

add_definitions(-DGLFW_INCLUDE_NONE
                -DDEVELOP
                -DPROJECT_SHADERS_DIR=\"${PROJECT_SHADERS_DIR}\"
                -DPROJECT_SOURCE_DIR=\"${PROJECT_SOURCE_DIR}\")
add_executable(${PROJECT_NAME} ${PROJECT_SOURCES} ${PROJECT_HEADERS}
                               ${PROJECT_SHADERS} ${PROJECT_CONFIGS})
target_link_libraries(${PROJECT_NAME} assimp glfw Qt5::Widgets SOIL
                      ${GLFW_LIBRARIES} ${GLAD_LIBRARIES}
                      BulletDynamics BulletCollision LinearMath)
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${PROJECT_NAME})
