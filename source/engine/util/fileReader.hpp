#pragma once


#include "engine/common.hpp"

#include <sstream>
#include <fstream>
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
            
            FileReader(const std::string & filepath);
			~FileReader();

			const const char & getData();
			const int & getSize();

        private:

            std::ifstream _filestream;
			char * _data;
			int _size;
			int _cursor;
	};

}