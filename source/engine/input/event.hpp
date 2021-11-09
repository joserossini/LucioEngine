#pragma once

#include <unordered_map>
#include <functional>
#include <tuple>

#include "engine/common.hpp"

namespace lucio {

	/*
	*	Event
	*/

	class Event {

		public:
			Event();
		    ~Event();
		
			void link(uint32_t key, CallBack<void,SDL_Event&> * callback);
			//TODO Delink
			void run();

		private:
			std::unordered_map<uint32_t, CallBack<void,SDL_Event&>*> * _eventMap;

	};
	
}