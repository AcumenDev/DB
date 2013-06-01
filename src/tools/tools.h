#ifndef TOOLS_H_INCLUDED
#define TOOLS_H_INCLUDED
#include <exception>
namespace Tools {
class NotImplementedException : public std::exception {
    virtual const char* what() const throw() {
        return "Not Implemented Exception ";
    }
};
}
#endif // TOOLS_H_INCLUDED
