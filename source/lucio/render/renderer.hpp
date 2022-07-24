#pragma once

#include "lucio/common.hpp"

namespace lucio {

	struct perspective_t
	{
		float width, height;
		double aspectRation;
		double fov;
	};

	struct view_t
	{
		int X, Y;
		int width, height;
	};

	/*
	*	Renderer 
	*/

	class Renderer {
		public:
			Renderer(Window & window);
			~Renderer();

			void setView(view_t & view);
			void clear() const;

			void render();

		private:
			Window & _window;
			view_t _view;

	};
}