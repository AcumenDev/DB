#include "FileSystem.h"

namespace Tools {
FileSystem::FileSystem() {
    //ctor
}

FileSystem::~FileSystem() {
    //dtor
}


bool FileSystem::DirCreate(std::string patch, std::string name) {
    std::string dir = patch + "/" + name;
    if ( mkdir(dir.c_str())) {
        return false;
    }
    return true;
}

bool FileSystem::FileSave(std::string patch, std::string name, std::string content) {
    return false;
}


}
