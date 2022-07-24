#pragma once


#include "lucio/common.hpp"
#include <strstream>

namespace lucio
{

	/*
	*	File
	*	Read files.
	*/

	class FileReader
    {
        public:
			static std::string GetDataFrom(const std::string& path);
	};

}
