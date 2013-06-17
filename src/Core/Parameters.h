#ifndef PARAMETERS_H
#define PARAMETERS_H
#include <iostream>
#include "Defines.h"
namespace Parameters
{
class Parameters
{
    public:
        Parameters();
        std::string GetPathToDB() const;
        std::string GetOutputDirPath() const;
        Core::DBType GetDBType() const;
        Core::Language GetLanguage() const;
        void SetPathToDB(std::string path);
        void SetOutputPath(std::string path);
        void SetDBType(Core::DBType type);
        void SetLanguage(Core::Language type);
        virtual ~Parameters();
    protected:
    private:
        std::string _PathToDB;
        std::string _OutputDirPath;
        Core::DBType _DBType;
        Core::Language _Language;
};
} //end Namespace Parameters
#endif // PARAMETERS_H
