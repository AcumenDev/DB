#ifndef SETTINGS_H
#define SETTINGS_H
#include <memory>
#include <iostream>
#include "../Connection/DefDB.h"

namespace Core
{
class Settings
{
public:
    virtual ~Settings() {};
    static std::shared_ptr<Settings>  GetSettings();
    void SetTemplateDir(std::string name);
    std::string GetTemplateDir() const;
    void SetOutputDir(std::string name);
    std::string GetOutputDir() const;
    void SetDBType(DB::DBType dbType);
     std::string GetOutputDirTables() const;
     void SetOutputDirTables(std::string name);
      std::string GetPathToOutputDirTables() const;
    DB::DBType GetDBType() const;
protected:
private:
    DB::DBType _DBType;
    std::string _OutputDir;
    std::string _OutputDirTables;
    std::string _TemplateDir;
    static     std::shared_ptr<Settings>  _Settings;
    Settings() {};
};
}//end namespace Core
#endif // SETTINGS_H
