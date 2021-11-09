#pragma once

#include "engine/common.hpp"

namespace lucio {

	/*
	*	App
	*/

	class App{
	
		public: 
			App();
			~App();
		 
			void run(const CallBack<void> loop);

			const Window & getWindow() const;

		private:
			void quit(SDL_Event & e);

		private:
			Window * _window;
			Renderer * _renderer;
			Event * _event;

			bool _quit;
			CallBack<void, SDL_Event&> * _quitCall;
	};
}