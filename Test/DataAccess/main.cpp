#include <iostream>
#include "DBEntityTestDB.h"

using namespace std;

int main() {
    DBEntityTestDB dbEntity("../../122.db","");

    for(const auto& row :dbEntity.Test1.GetList() ) {
        std::cout<<row.Id<<" "<<row.Name<<std::endl;
    }
   // cout << "Hello world!" << endl;
    return 0;
}
