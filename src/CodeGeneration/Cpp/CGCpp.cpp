#include "CGCpp.h"

namespace CG {

CGCpp::CGCpp() {
}

CGCpp::~CGCpp() {
}

void CGCpp::GenerateExternalFiles () {


}

void CGCpp::GenerateTablesStruct( const DBEntity::DBTable& dbTable)  {
    std::string content;
    for (const auto& field : dbTable.DBTableColumnList) {
        std::string  typeField ="\t\t";
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


    Tools::TemplateHelper tmpHelper;
    tmpHelper.OpenTemplate("Cpp/Tables/table_struct_h.tpl");
    tmpHelper.TextInsert(Tools::TEMPLATE_NAME_TABLE,dbTable.TableName);
    tmpHelper.TextInsert(Tools::TEMPLATE_BODY,content);

    Tools::FileSystem::FileSave(_Setting->GetOutputDir()+"/"+dbTable.TableName+"", dbTable.TableName+".h", tmpHelper.GetText());

}

void CGCpp::GenerateTablesLogic( const DBEntity::DBTable& dbTable)  {

    std::string tableName = dbTable.TableName+"Logic";

    Tools::TemplateHelper tmpHelper;
    tmpHelper.OpenTemplate("Cpp/Tables/table_logic_h.tpl");
    tmpHelper.TextInsert(Tools::TEMPLATE_NAME_TABLE,dbTable.TableName);


    Tools::FileSystem::FileSave(_Setting->GetOutputDir()+"/"+dbTable.TableName+"", tableName+".h", tmpHelper.GetText());


    std::string tab4 = "\t\t\t\t";
    int i = 0;
    std::string  contentCpp ;//=tab4+dbTable.TableName +" "+dbTable.TableName+"_;\n";
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


    tmpHelper.OpenTemplate("Cpp/Tables/table_logic_cpp.tpl");
    tmpHelper.TextInsert(Tools::TEMPLATE_NAME_TABLE,dbTable.TableName);
    tmpHelper.TextInsert(Tools::TEMPLATE_BODY,contentCpp);

    Tools::FileSystem::FileSave(_Setting->GetOutputDir()+"/"+dbTable.TableName+"", tableName+".cpp", tmpHelper.GetText());
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
