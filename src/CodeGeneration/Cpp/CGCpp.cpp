#include "CGCpp.h"

namespace CG {

CGCpp::CGCpp() {
}

CGCpp::~CGCpp() {
}

void CGCpp::GenerateTables() {
    std::string content;
    for(const auto& table : _dbModel.DBTableList) {
        Tools::FileSystem::DirCreate(_Setting->GetOutputDir(), table.TableName);
        content="#ifndef "+table.TableName +"_H\n#define "+table.TableName+"_H\n";
        content+="class "+table.TableName +" {\n";
        for (const auto& field : table.DBTableColumnList) {
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
        Tools::FileSystem::FileSave("./DB/"+table.TableName+"/", table.TableName+".h", content);
    }
}



void CGCpp::GenerateViews() {

}

void CGCpp::GenerateStoredProcedures() {

}


}
