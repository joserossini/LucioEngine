#include "fileReader.hpp"

//lucio::FileReader::FileReader(const std::string & filepath)
//{
//	
//	_filestream = std::ifstream();
//	_filestream.exceptions(std::ifstream::failbit | std::ifstream::badbit);
//
//	try {
//		_filestream.open(filepath, std::ifstream::binary);
//
//		if (_filestream.fail())
//			printf("\tERROR! 'fileReader.cpp' -> Fail to open: %s", filepath.c_str());
//
//		_filestream.seekg(0, std::ios::end);
//		_size = _filestream.tellg();
//		_filestream.seekg(0, std::ios::beg);
//		_data = std::unique_ptr<char[]> (new char[_size+1]);
//		_filestream.read(_data.get(), _size);
//		_data[_size] = '\0';
//		_filestream.close();
//	}
//	catch(std::ifstream::failure exception)
//	{
//		printf("\tERROR! -> Fail %s to succesfully read:", filepath.c_str());
//	}
//}
//
//lucio::FileReader::~FileReader()
//{
//	
//}
//
//const char & lucio::FileReader::getData()
//{
//	return _data;
//}
//
//const int & lucio::FileReader::getSize()
//{
//	return _size;
//}

std::string lucio::FileReader::GetDataFrom(const std::string& path)
{
	std::ifstream filestream = std::ifstream();
	std::string datastring;
	size_t size;


	filestream.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	try {
		filestream.open(path, std::ifstream::binary);

		if (filestream.fail()) {
			printf("\tERROR! 'fileReader.cpp' -> Fail to open: %s", path.c_str());
			return std::string();
		}
		filestream.seekg(0, std::ios::end);
		size = filestream.tellg();
		filestream.seekg(0, std::ios::beg);
		auto data = new char[size+1];
		filestream.read(std::move(data), size);
		data[size] = '\0';
		filestream.close();

		return std::string(data, size);
	}
	catch(std::ifstream::failure exception)
	{
		printf("\tERROR! -> Fail to succesfully read %s: %s", path.c_str(), exception.what());
	}

}
