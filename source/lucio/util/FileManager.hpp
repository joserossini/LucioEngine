#pragma once

#include "IFileManager.hpp"

namespace lucio::util
{
    class FileManager : public IFileManager 
    {
        virtual bool ReadFile(File& file) override;
		virtual File BuildFactory(string &filename, string &relativePath) override;
    };
}
