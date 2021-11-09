cmake_minimum_required(VERSION 3.13) # 3.13 INTERACE keyword relative path fix!
project(Lucio VERSION 0.0.1 LANGUAGES C CXX)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1z -Wall -Os -O3 ")
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
 
define_property( # Allow us to have multiple project on folders in VisualStudio
     TARGET 
     PROPERTY FOLDER
     INHERITED
     BRIEF_DOCS "Brief Doc"
     FULL_DOCS  "Full Doc"
 )

set(LUCIO_INLCUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/source)
set(LUCIO_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/source/engine)
set(SUBMODULES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/submodules)

set(OUT_LIB_DIR ${CMAKE_BINARY_DIR}/lib)
set(RUNTIME_DIR ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${RUNTIME_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUT_LIB_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${OUT_LIB_DIR})

link_directories(${OUT_LIB_DIR})

find_package(OpenGL REQUIRED)
add_subdirectory(submodules)
set_property(DIRECTORY submodules PROPERTY FOLDER "submodules")


File(GLOB LUCIO_INCLUDE_FILES
    ${LUCIO_SOURCE_DIR}/*.hpp
    ${LUCIO_SOURCE_DIR}/application/*.hpp
    ${LUCIO_SOURCE_DIR}/input/*.hpp
    ${LUCIO_SOURCE_DIR}/graphics/*.hpp
    ${LUCIO_SOURCE_DIR}/util/*.hpp
    )

File(GLOB LUCIO_SOURCE_FILES
    ${LUCIO_SOURCE_DIR}/application/*.cpp
    ${LUCIO_SOURCE_DIR}/input/*.cpp
    ${LUCIO_SOURCE_DIR}/graphics/*.cpp
    ${LUCIO_SOURCE_DIR}/util/*.cpp
    )

add_library(Lucio STATIC
    ${LUCIO_SOURCE_FILES}
    ${LUCIO_INCLUDE_FILES}
    )

target_link_libraries(Lucio 
    ${OPENGL_LIBRARY}
    SDL2-static
    glew_s
    gli
    glm
    nuklear_s
    stb_image
    )

target_include_directories(Lucio PUBLIC
    ${LUCIO_INLCUDE_DIR}
    ${OPENGL_INCLUDE_DIRS}
    ${NUK_INCLUDE}
    ${SUBMODULES_DIR}/sdl/include/
    ${SUBMODULES_DIR}/glew/include
    ${SUBMODULES_DIR}/glm
    ${SUBMODULES_DIR}/gli
    ${SUBMODULES_DIR}/stb
    )

add_subdirectory(sandbox)

if(MSVC)
    set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Sandbox)
endif()
