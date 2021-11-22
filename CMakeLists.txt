cmake_minimum_required(VERSION 3.22)

project(Lucio VERSION 0.0.1 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(LUCIO_INLCUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/source)
set(LUCIO_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/source/lucio)
set(SUBMODULES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/submodules)

set(OUT_LIB_DIR ${CMAKE_BINARY_DIR}/lib)
set(RUNTIME_DIR ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${RUNTIME_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUT_LIB_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${OUT_LIB_DIR})

link_directories(${OUT_LIB_DIR})

find_package(OpenGL REQUIRED)
add_subdirectory(submodules)

File(GLOB LUCIO_INCLUDE_FILES
    ${LUCIO_SOURCE_DIR}/*.hpp
    ${LUCIO_SOURCE_DIR}/core/*.hpp
    ${LUCIO_SOURCE_DIR}/render/*.hpp
    ${LUCIO_SOURCE_DIR}/util/*.hpp
    )

File(GLOB LUCIO_SOURCE_FILES
    ${LUCIO_SOURCE_DIR}/*.cpp
    ${LUCIO_SOURCE_DIR}/core/*.cpp
    ${LUCIO_SOURCE_DIR}/render/*.cpp
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
    stb_image
    )

target_include_directories(Lucio PUBLIC
    ${LUCIO_INLCUDE_DIR}
    ${OPENGL_INCLUDE_DIRS}
    ${SUBMODULES_DIR}/sdl/include
    ${SUBMODULES_DIR}/glew/include
    ${SUBMODULES_DIR}/glm
    ${SUBMODULES_DIR}/gli
    ${SUBMODULES_DIR}/stb
    )

add_subdirectory(sandbox)

if(MSVC)

    set_property(GLOBAL PROPERTY USE_FOLDERS ON) 

    # In adition to "USE_FOLDERS ON", this makes it work.
    define_property( 
        TARGET 
        PROPERTY FOLDER
        INHERITED
        BRIEF_DOCS "Brief Doc"
        FULL_DOCS  "Full Doc"
    )

    set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Sandbox)
    set_property(DIRECTORY submodules PROPERTY FOLDER "submodules")
    set_property(DIRECTORY submodules/glew/build/cmake PROPERTY FOLDER "submodules/glew")
    set_property(DIRECTORY submodules/gli PROPERTY FOLDER "submodules/gli")
    set_property(DIRECTORY submodules/gli/test PROPERTY FOLDER "submodules/gli/test")
    set_property(DIRECTORY submodules/glm PROPERTY FOLDER "submodules/glm")
    # TODO Replace nuklear with imgui
    #set_property(DIRECTORY submodules/nuklear PROPERTY FOLDER "submodules/nuklear")
    set_property(DIRECTORY submodules/sdl PROPERTY FOLDER "submodules/sdl")
    # STB is been include as a header lib.

endif()