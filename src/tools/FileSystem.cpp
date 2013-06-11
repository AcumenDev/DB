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
    }else
    {
        std::cout<<"Error dir create  : "<<dir<<std::endl;
    }
    return "";
}

bool FileSystem::FileSave(std::string path, std::string name, std::string content) {
    bool result=false;
    std::ofstream myfile;

    myfile.open(path+"/"+name);
    myfile << content;

    if (myfile.good()) {
        result= true;
        std::cout<<"Save file : "<<path+"/"+name<<std::endl;
    } else {
        std::cout<<"Error Save file : "<<path+"/"+name<<std::endl;
    }
    myfile.close();

    return result;
}
std::string FileSystem::OpenTemplateFile(std::string path) {
    std::shared_ptr<Core::Settings>  setting = Core::Settings::GetSettings();
    std::string templatePath =  setting->GetTemplateDir()+"/"+path;
    std::ifstream templateFile(templatePath, std::ios::in);
    if (templateFile.good()) {
        std::cout<<"Open template file : "<<templatePath<<std::endl;
    } else {
        std::cout<<"Error opening template file : "<<templatePath<<std::endl;
        return "";
    }
    std::ostringstream result;
    result << templateFile.rdbuf();
    return result.str();
}


}
