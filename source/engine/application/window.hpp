#pragma once

#include "engine/common.hpp"


namespace lucio {
    

	/*
	*	Window
	*	Initilize SDL2 and GLEW to creates a drawable window.
	*/

	class Window {
	 
		private:
		    SDL_Window * _window;
		    SDL_GLContext _glcontext;
		
		public:
		    Window(const char * title = "title", const int width = 800, const int height = 600);
		    ~Window();
		
		    SDL_Window * getSDLWindow() const;
		    SDL_GLContext getSDLGLContext() const;

			int getHeight() const;
			int getWidth() const;


			void swapBuffer();
	};

}

