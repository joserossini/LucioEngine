#include "filereader.hpp"
#include <fstream>

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
	return "";

}
