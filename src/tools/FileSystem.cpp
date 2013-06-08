#include "FileSystem.h"

namespace Tools {
FileSystem::FileSystem() {
    //ctor
}

FileSystem::~FileSystem() {
    //dtor
}


bool FileSystem::DirCreate(std::string path, std::string name) {
    std::string dir = path + "/" + name;
    if ( mkdir(dir.c_str())) {
        return false;
    }
    return true;
}

bool FileSystem::FileSave(std::string path, std::string name, std::string content) {
    bool result=false;
    std::ofstream myfile;

    myfile.open(path+"/"+name);
    myfile << content;

    if (myfile.good())
        result= true;

    myfile.close();

    return result;
}


}
