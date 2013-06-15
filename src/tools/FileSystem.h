#ifndef FILESYSTEM_H
#define FILESYSTEM_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <direct.h>
#include <memory>
#include "Settings.h"
#include "Log/LoggingSystem.h"
#include <iostream>
#include <boost/filesystem.hpp>

namespace Tools {
class FileSystem {
public:
    FileSystem() {};
    virtual ~FileSystem() {};

    static std::string DirCreate(std::string path,std::string  name );
    static std::string RootDirCreate(std::string name);
    static bool FileSave(std::string path,std::string  name,std::string  content );
    static std::string OpenTemplateFile(std::string path);
    static bool FileCopy(std::string from,std::string to);
protected:
private:
};
}//end namespace Tools
#endif // FILESYSTEM_H
