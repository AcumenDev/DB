#ifndef DBTABLECOLUMN_H
#define DBTABLECOLUMN_H
#include <iostream>

class DBTableColumn
{
    public:
        DBTableColumn(std::string name, std::string type);
        std::string Name;
        std::string Type;
        virtual ~DBTableColumn();
    protected:
    private:
};

#endif // DBTABLECOLUMN_H
