#include "renderer.hpp"

#include "engine/application/window.hpp"
#include <GL/glew.h>

lucio::Renderer::Renderer(Window & window):
	_window(window)
{
	glViewport(0, 0, _window.getWidth(), _window.getHeight());

	glClearColor(0.0f, 0.0f, 0.0f, 1.f);

}

lucio::Renderer::~Renderer()
{
}


void lucio::Renderer::setView(view_t & view)
{
	_view = view;
	glViewport(_view.X, _view.Y, _view.width, _view.width);
}

void lucio::Renderer::clear() const
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void lucio::Renderer::render()
{
	glFlush();
	_window.swapBuffer();\
}
