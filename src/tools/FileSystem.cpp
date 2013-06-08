#include "FileSystem.h"

namespace Tools {
FileSystem::FileSystem() {
    //ctor
}

FileSystem::~FileSystem() {
    //dtor
}


std::string FileSystem::DirCreate(std::string path, std::string name) {
    std::string dir = path + "/" + name;
    if ( mkdir(dir.c_str())) {
             std::cout<<"Create Dir : "<<dir<<std::endl;
        return dir;
    }
    return "";
}

bool FileSystem::FileSave(std::string path, std::string name, std::string content) {
    bool result=false;
    std::ofstream myfile;

    myfile.open(path+"/"+name);
    myfile << content;

    if (myfile.good()){
        result= true;
    std::cout<<"Save file : "<<path+"/"+name<<std::endl;
    }else
    {
    std::cout<<"Error Save file : "<<path+"/"+name<<std::endl;
    }
    myfile.close();

    return result;
}


}
