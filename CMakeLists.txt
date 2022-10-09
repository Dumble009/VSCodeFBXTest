cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")

set(ProjectName FBXTest)
set(LibraryName FBXTestLibrary)
set(ExecutableName FBXTestExe)

project(${ProjectName} VERSION 0.1.0)

include(CTest)
enable_testing()

file(GLOB_RECURSE LIB_SOURCES LIST_DIRECTORIES false RELATIVE "${CMAKE_SOURCE_DIR}" CONFIGURE_DEPENDS "libsources/*.cpp")
file(GLOB_RECURSE EXE_SOURCES LIST_DIRECTORIES false RELATIVE "${CMAKE_SOURCE_DIR}" CONFIGURE_DEPENDS "sources/*.cpp")

add_library(${LibraryName} ${LIB_SOURCES})
add_executable(${ExecutableName} ${EXE_SOURCES})

target_include_directories(${LibraryName} PUBLIC "${CMAKE_SOURCE_DIR}/libsources" "C:/Program Files/Autodesk/FBX/FBX SDK/2020.3.2/include")
target_link_directories(${LibraryName} PUBLIC "C:/Program Files/Autodesk/FBX/FBX SDK/2020.3.2/lib/vs2019/x64/debug")
target_link_libraries(${LibraryName} libfbxsdk)

target_include_directories(${ExecutableName} PUBLIC "${CMAKE_SOURCE_DIR}/sources" "${CMAKE_SOURCE_DIR}/libsources" "C:/Program Files/Autodesk/FBX/FBX SDK/2020.3.2/include")
target_link_directories(${ExecutableName} PUBLIC "C:/Program Files/Autodesk/FBX/FBX SDK/2020.3.2/lib/vs2019/x64/debug" "${CMAKE_SOURCE_DIR}/build")
target_link_libraries(${ExecutableName} libfbxsdk FBXTestLibrary)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)