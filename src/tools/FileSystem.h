#ifndef FILESYSTEM_H
#define FILESYSTEM_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <direct.h>
#include <memory>
#include "Settings.h"
namespace Tools {
class FileSystem {
public:
    FileSystem();
    virtual ~FileSystem();

    static std::string DirCreate(std::string path,std::string  name );
    static bool FileSave(std::string path,std::string  name,std::string  content );
    static std::string OpenTemplateFile(std::string path);

protected:
private:
};
}
#endif // FILESYSTEM_H
