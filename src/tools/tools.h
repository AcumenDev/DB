#ifndef TOOLS_H_INCLUDED
#define TOOLS_H_INCLUDED
#include <exception>

namespace Tools {
namespace Exception {
class NotImplementedException : public std::exception {
    virtual const char* what() const throw() {
        return "Not Implemented Exception ";
    }
};
} //end namespace Exception
}//end namespace Tools
#endif // TOOLS_H_INCLUDED
