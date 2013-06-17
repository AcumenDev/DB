#ifndef PARAMETERS_H
#define PARAMETERS_H
#include <iostream>
#include "../Connection/TableInfo.h"
namespace Parameters
{
class Parameters
{
    public:
        Parameters();
        std::string GetPathToDB() const;
        std::string GetOutputDirPath() const;
        std::string GetDBType() const;
        std::string GetLanguage() const;
        void SetPathToDB(std::string path);
        void SetOutputPath(std::string path);
        void SetDBType();
        void SetLanguage();
        virtual ~Parameters();
    protected:
    private:
        std::string _PathToDB;
        std::string _OutputPath;
        DB::DBType _DBType;
        std::string _Language;
};
} //end Namespace Parameters
#endif // PARAMETERS_H
