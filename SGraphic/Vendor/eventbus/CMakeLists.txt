cmake_minimum_required (VERSION 3.0)
project(eventbus)

include_directories(include)

file(GLOB PROJ_HEADERS include/*.hpp)
file(GLOB PROJ_SOURCES *.cpp)

add_library(${PROJECT_NAME} ${PROJ_HEADERS} ${PROJ_SOURCES})
