#include "CGCpp.h"

namespace CG {

CGCpp::CGCpp() {
}

CGCpp::~CGCpp() {
}

void CGCpp::GenerateTablesStruct( const DBEntity::DBTable& dbTable)  {
    std::string content;


    content="#ifndef "+dbTable.TableName +"_H\n#define "+dbTable.TableName+"_H\n";
    content+="class "+dbTable.TableName +" {\n";
    for (const auto& field : dbTable.DBTableColumnList) {
         std::string  typeField ="\t";
        switch (field.ColumnType) {
        case DB::DataType::Number: {
            typeField+="int";
            break;
        }
        case DB::DataType::Text: {
            typeField+="std::string";
            break;
        }
        }
        content+= typeField +" "+ field.ColumnName + ";\n";
    }
    content+="}\n#endif";
    Tools::FileSystem::FileSave(_Setting->GetOutputDir()+"/"+dbTable.TableName+"", dbTable.TableName+".h", content);

}

void CGCpp::GenerateTablesLogic( const DBEntity::DBTable& dbTable)  {
    std::string tableName = dbTable.TableName+"Logic";
    std::string contentH;
    contentH="#ifndef "+tableName +"_H\n#define "+tableName+"_H\n";
    contentH+="#include <"+dbTable.TableName+".h>\n";
    contentH+="class "+tableName +" {\n";
    for (const auto& field : dbTable.DBTableColumnList) {
//        switch (field.ColumnType) {
//        case DB::DataType::Number: {
//            contentH+="int ";
//            break;
//        }
//        case DB::DataType::Text: {
//            contentH+="std::string ";
//            break;
//        }
//        }
        //  content+= field.ColumnName + ";\n";
    }


    contentH+="\t"+tableName+"();\n\tvirtual ~"+tableName+"();\n";

    contentH+="\t"+tableName+" Test1_logic(const "+tableName+"&) = delete;\n";
    contentH+="\tvoid SetDBContext(sqlite3 * ppDb);\n";
    contentH+="\tstd::vector<"+dbTable.TableName +"> GetList();\n";


    contentH+="private:\n\tsqlite3 *_Db;\n\tint _Status ;";

    contentH+="\n}\n#endif";

    Tools::FileSystem::FileSave(_Setting->GetOutputDir()+"/"+dbTable.TableName+"", tableName+".h", contentH);






    std::string contentCpp;
    contentCpp="#include <"+tableName+".h>\n";

    for (const auto& field : dbTable.DBTableColumnList) {
//        switch (field.ColumnType) {
//        case DB::DataType::Number: {
//            content+="int ";
//            break;
//        }
//        case DB::DataType::Text: {
//            content+="std::string ";
//            break;
//        }
//        }
        //  content+= field.ColumnName + ";\n";
    }

    Tools::FileSystem::FileSave(_Setting->GetOutputDir()+"/"+dbTable.TableName+"", tableName+".cpp", contentCpp);


}



void CGCpp::GenerateTables() {
    for(const auto& table : _dbModel.DBTableList) {
        std::string path =  Tools::FileSystem::DirCreate(_Setting->GetOutputDir(), table.TableName);

        if(!path.empty()) {
            GenerateTablesStruct(table);
            GenerateTablesLogic(table);
        }
    }
}



void CGCpp::GenerateViews() {

}

void CGCpp::GenerateStoredProcedures() {

}
void CGCpp::Generate() {
    Tools::FileSystem::DirCreate(".",_Setting->GetOutputDir());
    CGBase::Generate();
}


}
