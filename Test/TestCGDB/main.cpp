#include <iostream>
#include "DBEntityTestDB.h"

using namespace std;

int main() {
    DBEntityTestDB dbEntity("../../TestDB.db");
    for(const auto& row :dbEntity.test1.GetList() ) {
        std::cout<<row.id<<" "<<row.name<<std::endl;
    }

    test2 _test2;
    _test2.name="name";
    _test2.number =12345;
    _test2.phone = "23241241";

    if(dbEntity.test2.Insert(_test2)) {

        for(const auto& row :dbEntity.test2.GetList() ) {
            std::cout<<row.number<<" "<<row.name<<" "<<row.phone<<std::endl;
        }
    }
    return 0;
}
