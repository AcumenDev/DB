#ifndef FILESYSTEM_H
#define FILESYSTEM_H
#include <iostream>
#include <direct.h>
namespace Tools {
class FileSystem {
public:
    FileSystem();
    virtual ~FileSystem();

    static bool DirCreate(std::string path,std::string  name );
    static bool FileSave(std::string path,std::string  name,std::string  content );

protected:
private:
};
}
#endif // FILESYSTEM_H
