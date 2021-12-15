#include "app.hpp"

#include "window.hpp"
#include "callback.hpp"
#include "event.hpp"
#include "lucio/render/renderer.hpp"
#include "lucio/render/shader.hpp"
#include "lucio/render/mesh.hpp"
#include "lucio/render/vertex.hpp"

#include <SDL.h>
#include <functional>
#include <iostream>

lucio::App::App():
	_window(new lucio::Window),
	_renderer(new lucio::Renderer(*_window)),
	_event(new lucio::Event),
	_quit(false),
	_quitCall(new CallBack<void, SDL_Event&>(std::bind(&lucio::App::quit, this, std::placeholders::_1)))
{
	_event->link(SDL_QUIT, _quitCall);
}

lucio::App::~App()
{
	
	delete (_event);
	delete (_window);
	delete (_renderer);
	delete (_quitCall);
}

void lucio::App::run(const CallBack<void> loop)
{
	while (!_quit)
	{
	_event->run();
	_renderer->clear();
	loop.execute();
	_renderer->render();
	}
}

void lucio::App::quit(SDL_Event & e)
{
#ifdef DEBUG
	std::clog << "Run time: " << e.quit.timestamp << "ms\n";
#endif // DEBUG
	_quit = true;
}



const lucio::Window & lucio::App::getWindow() const
{
	return *_window;
}
