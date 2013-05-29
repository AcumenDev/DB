#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED
#include <exception>
namespace Utils {
class NotImplementedException : public std::exception {
    virtual const char* what() const throw() {
        return "Not Implemented Exception ";
    }
};
}
#endif // UTILS_H_INCLUDED
