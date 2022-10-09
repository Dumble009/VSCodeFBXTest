cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")

set(ProjectName FBXTest)

project(${ProjectName} VERSION 0.1.0)


include(CTest)
enable_testing()

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES false RELATIVE "${CMAKE_SOURCE_DIR}" CONFIGURE_DEPENDS "sources/*.cpp")

add_library(${ProjectName} ${SOURCES})

target_include_directories(${ProjectName} PUBLIC "${CMAKE_SOURCE_DIR}/sources" "C:/Program Files/Autodesk/FBX/FBX SDK/2020.3.2/include")
target_link_directories(${ProjectName} PUBLIC "C:/Program Files/Autodesk/FBX/FBX SDK/2020.3.2/lib/vs2019/x64/debug")
target_link_libraries(${ProjectName} libfbxsdk)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)