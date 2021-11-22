#pragma once

#include <memory>
#include <map>
#include <functional>
#include <tuple>

#include "lucio/common.hpp"

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
			std::map<uint32_t, std::shared_ptr<CallBack<void,SDL_Event&>>> * _eventMap;

	};
	
}