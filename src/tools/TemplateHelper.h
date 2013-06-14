#ifndef TEMPLATEHELPER_H
#define TEMPLATEHELPER_H
#include <iostream>
#include "FileSystem.h"

namespace Tools {
const std::string TEMPLATE_DB_NAME = "[[DB_NAME]]";
const std::string TEMPLATE_NAME_TABLE = "[[NAME_TABLE]]";
const std::string TEMPLATE_BODY = "[[BODY]]";


class TemplateHelper {
public:
    TemplateHelper(){};
    virtual ~TemplateHelper(){};
    void OpenTemplate(std::string path);
    void TextInsert(std::string where,std::string text);
    std::string GetText();
protected:
    std::string TextRepalace(std::string&  text, std::string  toReplace, std::string  replaceWith);
private:
    std::string _Text;
};

}
#endif // TEMPLATEHELPER_H
