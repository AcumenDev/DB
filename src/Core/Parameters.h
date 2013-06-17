#ifndef PARAMETERS_H
#define PARAMETERS_H
#include <iostream>
#include <memory>
#include "Defines.h"
#include "Settings.h"
namespace Core
{
class Parameters
{
    public:
        Parameters() {};
        Parameters(int argc, char *argv[], std::shared_ptr<Settings> settings);
        std::string GetPathToDB() const;
        std::string GetPathToOutputDir() const;
        DBType GetDBType() const;
        Language GetLanguage() const;
        void SetPathToDB(std::string path);
        void SetPathToOutputDir(std::string path);
        void SetDBType(DBType type);
        void SetLanguage(Language type);
        virtual ~Parameters();
    protected:
    private:
        std::string _PathToDB;
        std::string _PathToOutputDir;
        DBType _DBType;
        Language _Language;
};
} //end Namespace Core
#endif // PARAMETERS_H

