## Boost:ext di ##
add_subdirectory("boost-ext-di" EXCLUDE_FROM_ALL)

## SDL2 ##
set(SDL_STATIC ON)
set(SDL_SHARED OFF)
add_subdirectory(sdl2 EXCLUDE_FROM_ALL)

## GLM ##+
add_subdirectory(glm EXCLUDE_FROM_ALL)

## GLI ##
add_subdirectory(gli EXCLUDE_FROM_ALL)


## GLEW ##
add_subdirectory(glew/build/cmake EXCLUDE_FROM_ALL)

# TODO Replace nuklear with imgui
## NUKLEAR ##
#project(nuklear_s)
#file(GLOB NUK_INCLUDE nuklear/src/*.h)
#file(GLOB NUK_SRC nuklear/src/*.c)
#add_library (nuklear_s STATIC 
#    ${NUK_INCLUDE}
#    ${NUK_SRC})
#set_target_properties(nuklear_s PROPERTIES LINKER_LANGUAGE C)

## STB_IMAGE ##
add_library (stb_image INTERFACE)
target_sources (stb_image INTERFACE stb/stb_image.h)
target_include_directories(stb_image INTERFACE stb)
