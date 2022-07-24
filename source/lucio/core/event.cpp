#include "event.hpp"
#include "callback.hpp"
#include <SDL.h>

lucio::Event::Event():
	_eventMap(new std::map<uint32_t,std::shared_ptr<CallBack<void,SDL_Event&>>>)
{
}

lucio::Event::~Event()
{
	delete(_eventMap);
}

void lucio::Event::link(uint32_t key, CallBack<void, SDL_Event&> * callback)
{
	_eventMap->insert(std::make_pair(key,callback));
}


void lucio::Event::run()
{
	SDL_Event e;
	if (SDL_PollEvent(&e) != 0) {
		if(_eventMap->find(e.type) != _eventMap->end())
		_eventMap->at(e.type)->execute(e);
	}
}

