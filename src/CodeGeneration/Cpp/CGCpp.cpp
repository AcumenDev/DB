#include "CGCpp.h"

namespace CG {

CGCpp::CGCpp() {
}

CGCpp::~CGCpp() {
}

void CGCpp::GenerateTables() {

    std::string content="";
    for(const auto& table : _dbModel.DBTableList) {
        content+="class "+table.TableName +" {\n ";
        for (const auto& field : table.DBTableColumnList)
        {
            switch (field.ColumnType)
            {
            case DB::DataType::Number:
                {
                    content+="int ";
                    break;
                }
            case DB::DataType::Text:
                {
                    content+="string ";
                    break;
                }
            }
            content+= field.ColumnName + ";";
        }
    content+="}";
    }
}



void CGCpp::GenerateViews() {

}

void CGCpp::GenerateStoredProcedures() {

}


}
