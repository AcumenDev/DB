#ifndef CGCPP_H
#define CGCPP_H
#include "../CGBase.h"
namespace CG {
class CGCpp : public  CGBase{
public:
    CGCpp();
    virtual ~CGCpp();
    /** @brief (one liner)
      *
      * (documentation goes here)
      */
    void GenerateTables() override;


protected:
private:
};
}
#endif // CGCPP_H
