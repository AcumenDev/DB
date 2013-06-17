#ifndef SETTINGS_H
#define SETTINGS_H
#include <memory>
#include <iostream>
#include "../Core/DefDB.h"

namespace Core {
class Settings {
public:
    virtual ~Settings() {};
    static std::shared_ptr<Settings>  GetSettings();
    void SetTemplateDir(std::string name);
    std::string GetTemplateDir() const;
    void SetOutputDir(std::string name);
    std::string GetOutputDir() const;
    void SetDBType(Core::DBType dbType);
    std::string GetOutputDirTables() const;
    void SetOutputDirTables(std::string name);
    std::string GetPathToOutputDirTables() const;
    void SetPathToDB(std::string path);
    std::string GetPathToDB();
    void SetLanguage(std::string name);
//    Core::Language GetLanguage();
    Core::DBType GetDBType() const;
protected:
private:
    Core::DBType _DBType;
    std::string _OutputDir;
    std::string _OutputDirTables;
    std::string _TemplateDir;
    std::string _PathToDB;
  //  Core::Language _Language;
    static     std::shared_ptr<Settings>  _Settings;
    Settings() {};
};
}//end namespace Core
#endif // SETTINGS_H
