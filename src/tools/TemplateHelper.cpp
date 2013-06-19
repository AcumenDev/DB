#include "TemplateHelper.h"

namespace Tools {

std::string TemplateHelper::TextRepalace(std::string&  text, std::string  toReplace, std::string  replaceWith) {
    int nPos =  text.find(toReplace);
    while(nPos!=-1) {
        text.replace(nPos,toReplace.length(),replaceWith);
        nPos =  text.find(toReplace);
    }
    return  text;
}

void TemplateHelper::OpenTemplate(std::string path) {
    _Text =  FileSystem::OpenTemplateFile(path);
}

void TemplateHelper::TextInsert(std::string where, std::string text) {
    TextRepalace(_Text,where,text);
}

std::string TemplateHelper::GetText()const {
    return _Text;
}
}//end namespace Tools
