#include "fileReader.hpp"

lucio::FileReader::FileReader(const std::string & filepath):
	_data(nullptr),
	_cursor(0),
	_size(0)
{
	
	_filestream = std::ifstream();
	_filestream.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	try {
		_filestream.open(filepath, std::ifstream::binary);

		if (_filestream.fail())
			printf("\tERROR! 'fileReader.cpp' -> Fail to open: %s", filepath.c_str());

		_filestream.seekg(0, std::ios::end);
		_size = _filestream.tellg();
		_filestream.seekg(0, std::ios::beg);
		_data = new char[_size+1];
		_filestream.read(_data, (_size));
		_data[_size] = '\0';
		_filestream.close();
	}
	catch(std::ifstream::failure exception)
	{
		printf("\tERROR! -> Fail %s to succesfully read:", filepath.c_str());
	}
}

lucio::FileReader::~FileReader()
{
	delete _data;
}

const char & lucio::FileReader::getData()
{
	return *_data;
}

const int & lucio::FileReader::getSize()
{
	return _size;
}
