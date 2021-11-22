#include "window.hpp"

#include <GL/glew.h>
#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <SDL_opengl.h>

lucio::Window::Window(const char* title, const int width, const int height)
{
    if(SDL_Init(SDL_INIT_VIDEO) != 0)
        throw "SDL Video Fail to Initilize";

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4); 
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);

	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    _window = SDL_CreateWindow(  
        title,
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        width,
        height,
        SDL_WINDOW_OPENGL | SDL_WINDOW_ALLOW_HIGHDPI);
    
    _glcontext = SDL_GL_CreateContext(_window);

	/* Not required in GLEW +2.0 */
	//glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK)
		throw "GLEW Fail to Initilize";

}

lucio::Window::~Window()
{
    SDL_GL_DeleteContext(&_glcontext);
    SDL_DestroyWindow(_window);
    SDL_Quit();

    delete(_glcontext);
}

SDL_GLContext lucio::Window::getSDLGLContext() const
{
    return _glcontext;
}

int lucio::Window::getHeight() const
{
	return SDL_GetWindowSurface(_window)->h;
}

int lucio::Window::getWidth() const
{
	return SDL_GetWindowSurface(_window)->w;
}

void lucio::Window::swapBuffer()
{
	SDL_GL_SwapWindow(_window);
}

SDL_Window* lucio::Window::getSDLWindow() const
{
    return _window;
}