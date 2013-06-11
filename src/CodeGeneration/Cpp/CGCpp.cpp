#include "CGCpp.h"

namespace CG {

CGCpp::CGCpp() {
}

CGCpp::~CGCpp() {
}

void CGCpp::GenerateExternalFiles () {
    Tools::TemplateHelper tmpHelper;
    tmpHelper.OpenTemplate("Cpp/DBentity_h.tpl");
    tmpHelper.TextInsert(Tools::TEMPLATE_DB_NAME, _dbModel.DBName);

    std::string include_block_content; //в .h файле строки где подключаются хедеры из /Tables/
    std::string logic_var_block_content; //в .h файле строки где объявляются переменные табличной логики
    std::string set_dbcontext_block_content; //в cpp файле где передается dbcontext в файлы табличной логики

    for(const auto& table : _dbModel.DBTableList) {
        include_block_content+="\n#include ""Tables/"+table.TableName+"/"+table.TableName+"_logic.h";

        logic_var_block_content+="\n"+table.TableName+"_logic "+table.TableName+";";

        set_dbcontext_block_content+="\n"+table.TableName+".SetDBContext(_Db);";
    }

    tmpHelper.TextInsert("[[INCLUDE_BLOCK]]", include_block_content);
    tmpHelper.TextInsert("[[LOGIC_VAR_BLOCK]]", logic_var_block_content);
    Tools::FileSystem::FileSave(_Setting->GetOutputDir()+"/", "DBEntity"+ _dbModel.DBName+".h", tmpHelper.GetText());

    tmpHelper.OpenTemplate("Cpp/DBentity_cpp.tpl");
    tmpHelper.TextInsert(Tools::TEMPLATE_DB_NAME, _dbModel.DBName);

    tmpHelper.TextInsert("[[SET_DBCONTEXT_BLOCK]]", set_dbcontext_block_content);
    Tools::FileSystem::FileSave(_Setting->GetOutputDir()+"/", "DBEntity"+ _dbModel.DBName+".cpp", tmpHelper.GetText());
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

    GenerateExternalFiles();
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
