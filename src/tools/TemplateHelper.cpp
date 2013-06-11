#include "TemplateHelper.h"
namespace Tools {
TemplateHelper::TemplateHelper() {
    //ctor
}

TemplateHelper::~TemplateHelper() {
    //dtor
}


std::string TemplateHelper::TextRepalace(std::string&  text, std::string  toReplace, std::string  replaceWith) {


//  std::cout << "Original string: \t" << text << std::endl;
    int nPos =  text.find(toReplace);
    while(nPos!=-1) {
        text.replace(nPos,toReplace.length(),replaceWith);
        nPos =  text.find(toReplace);
    }
    // std::cout << "After replacing: \t" << text << std::endl << std::endl;
    return  text;
}


void TemplateHelper::OpenTemplate(std::string path) {
    _Text =  FileSystem::OpenTemplateFile(path);
}

void TemplateHelper::TextInsert(std::string where, std::string text) {
    TextRepalace(_Text,where,text);
}

std::string TemplateHelper::GetText() {
    return _Text;
}


}
