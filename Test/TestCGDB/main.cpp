#include <iostream>
#include "DBEntityTestDB.h"

using namespace std;

int main() {
    DBEntityTestDB dbEntity("../../TestDB.db");
        for(const auto& row :dbEntity.test1.GetList() ) {
        std::cout<<row.id<<" "<<row.name<<std::endl;
    }
    return 0;
}
