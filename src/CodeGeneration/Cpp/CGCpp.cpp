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
    // for (const auto& field : dbTable.DBTableColumnList) {
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
    // }


    contentH+="\t"+tableName+"();\n\tvirtual ~"+tableName+"();\n";

    contentH+="\t"+tableName+" Test1_logic(const "+tableName+"&) = delete;\n";
    contentH+="\tvoid SetDBContext(sqlite3 * ppDb);\n";
    contentH+="\tstd::vector<"+dbTable.TableName +"> GetList();\n";


    contentH+="private:\n\tsqlite3 *_Db;\n\tint _Status ;";

    contentH+="\n}\n#endif";

    Tools::FileSystem::FileSave(_Setting->GetOutputDir()+"/"+dbTable.TableName+"", tableName+".h", contentH);






    std::string contentCpp;
    contentCpp="#include <"+tableName+".h>\n";
    contentCpp+=tableName+"::"+tableName+"(){\n}\n";
    contentCpp+=tableName+"::~"+tableName+"(){\n}\n";

    contentCpp+="void "+tableName+"::SetDBContext(sqlite3* ppDb) {\n";
    contentCpp+="\tthis->_Db = ppDb;\n}\n";
    contentCpp+="std::vector<"+dbTable.TableName+"> "+tableName+"::GetList() {\n";

    contentCpp+="\tconst std::string GET_DATA_TABLE = \"select id, name from "+dbTable.TableName+"\";\n";
    contentCpp+="\tstd::vector<"+dbTable.TableName+"> vectorResult;\n";


    contentCpp+="\tchar  *pSQL2;\n";
    contentCpp+="\tsqlite3_stmt *stmt;\n";
    contentCpp+="\tint rc;\n";
    contentCpp+="\trc = sqlite3_prepare_v2(_Db, GET_DATA_TABLE.c_str(), -1, &stmt, (const char**)&pSQL2);\n";

    contentCpp+="\tif (rc == SQLITE_OK) {\n";
    contentCpp+="\t\tif (sqlite3_column_count(stmt)) {\n";

    std::string tab4 = "\t\t\t\t";
    contentCpp+="\t\t\twhile ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {\n";


    //  auto rawId = sqlite3_column_int(stmt, 0);
    //  auto rawName = sqlite3_column_text(stmt, 1);


//    Test1 test1;
    //  test1.Id = rawId;
//   test1.Name = reinterpret_cast<const char*>(rawName);
    //  vectorResult.push_back(test1);


    int i = 0;
    contentCpp+=tab4+dbTable.TableName +" "+dbTable.TableName+"_;\n";
    for (const auto& field : dbTable.DBTableColumnList) {
        std::string sqlite3call;
        switch (field.ColumnType) {
        case DB::DataType::Number: {
            sqlite3call="sqlite3_column_int(stmt, "+std::to_string(i)+");\n";
            break;
        }
        case DB::DataType::Text: {
            sqlite3call="reinterpret_cast<const char*>(sqlite3_column_text(stmt, "+std::to_string(i)+"));\n";
            break;
        }
        }
        ++i;

        contentCpp+=tab4+dbTable.TableName+"_."+field.ColumnName+" = "+sqlite3call;

    }
contentCpp+=tab4+"vectorResult.push_back("+dbTable.TableName+"_."+");\n";

    contentCpp+="\t\t\t}\n";
     contentCpp+="\t\t}\n";
    contentCpp+="\tsqlite3_finalize(stmt);\n";
    contentCpp+="\t} else {\n";
    contentCpp+="\tstd::cout<<\"Error: %s\\n  \"<<sqlite3_errmsg(_Db);\n";
    contentCpp+="\t}\n";
    contentCpp+="return vectorResult;\n}";



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
