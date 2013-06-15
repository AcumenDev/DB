#include "FileSystem.h"

namespace Tools
{

std::string FileSystem::DirCreate(std::string path, std::string name)
{
    std::shared_ptr<LoggingSystem> _Log  =  LoggingSystem::GetLoggingSystem();
    std::string dir = path + "/" + name;
    if ( mkdir(dir.c_str()))
    {
        _Log->Write("Create Dir : "+dir,LogType::Messages);
        return dir;
    }
    else
    {
        _Log->Write("Error dir create  : "+dir,LogType::Error);
    }
    return "";
}

bool FileSystem::FileSave(std::string path, std::string name, std::string content)
{
    std::shared_ptr<LoggingSystem> _Log  =  LoggingSystem::GetLoggingSystem();
    bool result=false;
    std::ofstream myfile;
    myfile.open(path+"/"+name);
    myfile << content;
    if (myfile.good())
    {
        result= true;
        _Log->Write("Save file : "+path+"/"+name,LogType::Messages);
    }
    else
    {
        _Log->Write("Error Save file : "+path+"/"+name,LogType::Messages);
    }
    myfile.close();
    return result;
}
std::string FileSystem::OpenTemplateFile(std::string path)
{
    std::shared_ptr<LoggingSystem> _Log  =  LoggingSystem::GetLoggingSystem();
    std::shared_ptr<Core::Settings>  setting = Core::Settings::GetSettings();
    std::string templatePath =  setting->GetTemplateDir()+"/"+path;
    std::ifstream templateFile(templatePath, std::ios::in);
    if (templateFile.good())
    {
        _Log->Write("Open template file : "+templatePath,LogType::Messages);
    }
    else
    {
        _Log->Write("Error opening template file : "+templatePath,LogType::Messages);
        return "";
    }
    std::ostringstream result;
    result << templateFile.rdbuf();
    return result.str();
}
}//end namespace Tools
