#pragma once

#include <string>
#include <memory>

using namespace std;

namespace lucio::util
{

	/*
	*	file_t
	*	Represents a file/document.
	*
	*/

	struct file_t
    {
		string name = "";
		string relative_path = "";
		string data = "";
		string path() {return relative_path + name;}
    };

	/*
	*	File
	*	A file_t wrap on a shared pointer for easy and clean handling.
	*
	*/
	typedef shared_ptr<file_t> File;

	/*
	*	IFileManager
	*	An "Interface" that standarizes the behaviour a FileManager.
	*	
	*/

	struct IFileManager
    {
		public:
		
		virtual ~IFileManager() noexcept = default;

        virtual bool ReadFile(File& file) = 0;
		virtual File BuildFactory(string &filename, string &relativePath) = 0;
    };

}