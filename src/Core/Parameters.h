#ifndef PARAMETERS_H
#define PARAMETERS_H
#include <iostream>
#include "Defines.h"

namespace Core
{
class Parameters
{
    public:
        Parameters() {};
        Parameters(int argc, char *argv[]);
        std::string GetPathToDB() const;
        std::string GetOutputDirPath() const;
        DBType GetDBType() const;
        Language GetLanguage() const;
        void SetPathToDB(std::string path);
        void SetOutputPath(std::string path);
        void SetDBType(DBType type);
        void SetLanguage(Language type);
        virtual ~Parameters();
    protected:
    private:
        std::string _PathToDB;
        std::string _OutputDirPath;
        DBType _DBType;
        Language _Language;
};
} //end Namespace Core
#endif // PARAMETERS_H

