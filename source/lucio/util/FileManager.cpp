#include "FileManager.hpp"
#include "IFileManager.hpp"
#include <fstream>

using namespace lucio::util;

bool FileManager::ReadFile (File& file) 
{
    ifstream filestream = ifstream();
    size_t size = 0;
    filestream.exceptions(ifstream::failbit | ifstream::badbit);
    try {
    	filestream.open(file->path(), ifstream::binary);
    	if (filestream.fail()) {
    		printf("\tERROR! 'fileReader.cpp' -> Fail to open: %s", file->name.c_str());
    		return false;
    	}
        
    	filestream.seekg(0, ios::end);
    	size = filestream.tellg();
    	filestream.seekg(0, ios::beg);
    	auto data = new char[size+1];
    	filestream.read(move(data), size);
    	data[size] = '\0';
    	filestream.close();
        file->data = string(data, size);

    	return true;
    }
    catch(ifstream::failure exception)
    {
    	printf("\tERROR! -> Fail to succesfully read %s: %s", file->name.c_str(), exception.what());
        return false;
    }

};

File FileManager::BuildFactory(string &filename, string &relativePath) 
{
    return make_shared<file_t> (file_t {filename, relativePath}); 
};        
