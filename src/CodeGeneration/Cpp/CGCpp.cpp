#include "CGCpp.h"

namespace CG {

CGCpp::CGCpp() {
}

CGCpp::~CGCpp() {
}

void CGCpp::GenerateTablesStruct(DBEntity::DBTable dbTable) {
    std::string content;

    Tools::FileSystem::DirCreate(_Setting->GetOutputDir(), dbTable.TableName);
    content="#ifndef "+dbTable.TableName +"_H\n#define "+dbTable.TableName+"_H\n";
    content+="class "+dbTable.TableName +" {\n";
    for (const auto& field : dbTable.DBTableColumnList) {
        switch (field.ColumnType) {
        case DB::DataType::Number: {
            content+="int ";
            break;
        }
        case DB::DataType::Text: {
            content+="std::string ";
            break;
        }
        }
        content+= field.ColumnName + ";\n";
    }
    content+="}\n";
    Tools::FileSystem::FileSave("./DB/"+dbTable.TableName+"/", dbTable.TableName+".h", content);

}

void CGCpp::GenerateTablesLogic(DBEntity::DBTable dbTable) {



}



void CGCpp::GenerateTables() {
    for(const auto& table : _dbModel.DBTableList) {
        GenerateTablesStruct(table);
        GenerateTablesLogic(table);
    }
}



void CGCpp::GenerateViews() {

}

void CGCpp::GenerateStoredProcedures() {

}


}
