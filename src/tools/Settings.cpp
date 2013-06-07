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
}
