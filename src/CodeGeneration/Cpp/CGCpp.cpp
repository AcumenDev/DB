#include "CGCpp.h"

namespace CG {

void CGCpp::GenerateExternalFiles () {
    Tools::TemplateHelper tmpHelper;
    tmpHelper.OpenTemplate("Cpp/DBentity_h.tpl");
    tmpHelper.TextInsert(Tools::TEMPLATE_DB_NAME, _dbModel.GetDBName());

    std::string include_block_content; //в .h файле строки где подключаютс€ хедеры из /Tables/
    std::string logic_var_block_content; //в .h файле строки где объ€вл€ютс€ переменные табличной логики
    std::string set_dbcontext_block_content; //в cpp файле где передаетс€ dbcontext в файлы табличной логики

    for(const auto& table : _dbModel.DBTableList) {
        include_block_content+="\n#include ""\"Tables/"+table.GetTableName()+"/"+table.GetTableName()+"Logic.h\"";
        logic_var_block_content+="\n"+table.GetTableName()+"Logic "+table.GetTableName()+";";
        set_dbcontext_block_content+="\n"+table.GetTableName()+".SetDBContext(_Db);";
    }

    tmpHelper.TextInsert("[[INCLUDE_BLOCK]]", include_block_content);
    tmpHelper.TextInsert("[[LOGIC_VAR_BLOCK]]", logic_var_block_content);
    Tools::FileSystem::FileSave(_Setting->GetOutputDir(), "DBEntity"+ _dbModel.GetDBName()+".h", tmpHelper.GetText());

    tmpHelper.OpenTemplate("Cpp/DBentity_cpp.tpl");
    tmpHelper.TextInsert(Tools::TEMPLATE_DB_NAME, _dbModel.GetDBName());

    tmpHelper.TextInsert("[[SET_DBCONTEXT_BLOCK]]", set_dbcontext_block_content);
    Tools::FileSystem::FileSave(_Setting->GetOutputDir(), "DBEntity"+ _dbModel.GetDBName()+".cpp", tmpHelper.GetText());
}

void CGCpp::GenerateTablesStruct( const DBEntity::DBTable& dbTable,std::string path) {
    std::string content;
    for (const auto& field : dbTable.DBTableColumnList) {
        std::string  typeField ="\t\t";
        switch (field.GetColumnDataType()) {
        case Core::DataType::Number: {
            typeField+="int";
            break;
        }
        case Core::DataType::Text: {
            typeField+="std::string";
            break;
        }
        }
        content+= typeField +" "+ field.GetColumnName() + ";\n";
    }

    Tools::TemplateHelper tmpHelper;
    tmpHelper.OpenTemplate("Cpp/Tables/table_struct_h.tpl");
    tmpHelper.TextInsert(Tools::TEMPLATE_NAME_TABLE,dbTable.GetTableName());
    tmpHelper.TextInsert(Tools::TEMPLATE_BODY,content);

    Tools::FileSystem::FileSave(path, dbTable.GetTableName()+".h", tmpHelper.GetText());
}

void CGCpp::GenerateTablesLogic( const DBEntity::DBTable& dbTable,std::string path) {

    std::string tableName = dbTable.GetTableName()+"Logic";
    Tools::TemplateHelper tmpHelper;
    tmpHelper.OpenTemplate("Cpp/Tables/table_logic_h.tpl");
    tmpHelper.TextInsert(Tools::TEMPLATE_NAME_TABLE,dbTable.GetTableName());
    Tools::FileSystem::FileSave(path, tableName+".h", tmpHelper.GetText());

    std::string tab4 = "\t\t\t\t";
    int i = 0;
    std::string  contentCpp ;
    for (const auto& field : dbTable.DBTableColumnList) {
        std::string sqlite3call;
        switch (field.GetColumnDataType()) {
        case Core::DataType::Number: {
            sqlite3call="sqlite3_column_int(stmt, "+std::to_string(i)+");\n";
            break;
        }
        case Core::DataType::Text: {
            sqlite3call="reinterpret_cast<const char*>(sqlite3_column_text(stmt, "+std::to_string(i)+"));\n";
            break;
        }
        }
        ++i;
        contentCpp+=tab4+dbTable.GetTableName()+"_."+field.GetColumnName()+" = "+sqlite3call;
    }

    tmpHelper.OpenTemplate("Cpp/Tables/table_logic_cpp.tpl");
    tmpHelper.TextInsert(Tools::TEMPLATE_NAME_TABLE,dbTable.GetTableName());
    tmpHelper.TextInsert(Tools::TEMPLATE_BODY,contentCpp);

    Tools::FileSystem::FileSave(path, tableName+".cpp", tmpHelper.GetText());
}

void CGCpp::GenerateTables() {
    std::string pathToTables= Tools::FileSystem::DirCreate(_Setting->GetOutputDir(), _Setting->GetOutputDirTables());
    for(const auto& table : _dbModel.DBTableList) {
        std::string path =  Tools::FileSystem::DirCreate(pathToTables, table.GetTableName());

        if(!path.empty()) {
            GenerateTablesStruct(table,path);
            GenerateTablesLogic(table,path);
        }
    }
    GenerateExternalFiles();
}

void CGCpp::GenerateViews() {

}

void CGCpp::GenerateStoredProcedures() {

}

void CGCpp::Generate() {
    Tools::FileSystem::RootDirCreate(_Setting->GetOutputDir());
    CopyLib();
    CGBase::Generate();
}
void CGCpp::CopyLib() {
    std::string dirOutput =  Tools::FileSystem::DirCreate(_Setting->GetOutputDir(), "external_lib");
    Tools::FileSystem::FileCopy(_Setting->GetTemplateDir()+"/external_lib/sqlite3/include/sqlite3.h",dirOutput+"/sqlite3.h");
    Tools::FileSystem::FileCopy(_Setting->GetTemplateDir()+"/external_lib/sqlite3/include/sqlite3ext.h",dirOutput+"/sqlite3ext.h");
}

}//end namespace CG
