#include "FileSystem.h"

namespace Tools {

std::string FileSystem::DirCreate(std::string path, std::string name) {
    std::shared_ptr<LoggingSystem> _Log  =  LoggingSystem::GetLoggingSystem();
    if(path.empty()) {
        _Log->Write("Error dir "+name+" create path is empty ",LogType::Error);
        return "";
    }



    std::string dir = path + "/"+name;


    boost::filesystem::path dirc(dir);

    if(boost::filesystem::exists(dirc)) {
        return dir;
    }
    if ( boost::filesystem::create_directory(dirc)) {
        _Log->Write("Create dir : "+dir,LogType::Messages);
        return dir;
    } else {
        _Log->Write("Error  dir create  : "+dir,LogType::Error);
    }
    return "";
}

std::string FileSystem::RootDirCreate(std::string dirName) {
    std::shared_ptr<LoggingSystem> _Log  =  LoggingSystem::GetLoggingSystem();
    boost::filesystem::path dirc(dirName);

    if(boost::filesystem::exists(dirc)) {
            boost::filesystem::remove_all(dirc) ;
       // return dirName;
    }
    if ( boost::filesystem::create_directory(dirc)) {
        _Log->Write("Create root dir : "+dirName,LogType::Messages);
        return dirName;
    } else {
        _Log->Write("Error root dir create  : "+dirName,LogType::Error);
    }
    return "";
}

bool FileSystem::FileSave(std::string path, std::string name, std::string content) {
    std::shared_ptr<LoggingSystem> _Log  =  LoggingSystem::GetLoggingSystem();
    bool result=false;
    std::ofstream myfile;
    myfile.open(path+"/"+name);
    myfile << content;
    if (myfile.good()) {
        result= true;
        _Log->Write("Save file : "+path+"/"+name,LogType::Messages);
    } else {
        _Log->Write("Error Save file : "+path+"/"+name,LogType::Error);
    }
    myfile.close();
    return result;
}
std::string FileSystem::OpenTemplateFile(std::string path) {
    std::shared_ptr<LoggingSystem> _Log  =  LoggingSystem::GetLoggingSystem();
    std::shared_ptr<Core::Settings>  setting = Core::Settings::GetSettings();
    std::string templatePath =  setting->GetTemplateDir()+"/"+path;
    std::ifstream templateFile(templatePath, std::ios::in);
    if (templateFile.good()) {
        _Log->Write("Open template file : "+templatePath,LogType::Messages);
    } else {
        _Log->Write("Error opening template file : "+templatePath,LogType::Error);
        return "";
    }
    std::ostringstream result;
    result << templateFile.rdbuf();
    return result.str();
}
bool FileSystem::FileCopy(std::string from, std::string to) {


    std::shared_ptr<LoggingSystem> _Log  =  LoggingSystem::GetLoggingSystem();


    _Log->Write("Copy file from : "+from+" to "+to,LogType::Messages);
    boost::filesystem::path fromPath(from);
    boost::filesystem::path toPath(to);

    boost::system::error_code ec;
    if(!boost::filesystem::exists(fromPath)) {
        return false;
    }



    try {
        // boost::filesystem::copy_file( fromPath, toPath );
        boost::filesystem::copy(fromPath,toPath);
    } catch (const boost::filesystem::filesystem_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        _Log->Write("Error copy file from : "+from+" to "+to+" "+e.what(),LogType::Error);
        return false;
    }
    return true;
}

}//end namespace Tools
