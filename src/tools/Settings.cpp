#include "Settings.h"
namespace Core {


std::shared_ptr<Settings> Settings::_Settings=nullptr;

std::shared_ptr<Settings>  Settings::GetSettings() {
    if(_Settings ==nullptr) {
        _Settings =   std::shared_ptr<Settings> (new Settings());

    }
    return _Settings;
}



Settings::Settings() {
    //ctor
}

Settings::~Settings() {
    //dtor
}

void Settings::SetOutputDir(std::string name) {
    _OutputDir=name;
}

std::string Settings::GetOutputDir() const {
    return  _OutputDir;
}

void Settings::SetDBType(DB::DBType dbType)
{
    _DBType = dbType;
}

DB::DBType Settings::GetDBType() const
{
    return _DBType;
}


void Settings::SetTemplateDir(std::string name)
{
    _TemplateDir = name;
}

std::string Settings::GetTemplateDir() const
{
    return _TemplateDir;
}



}
