#include <iostream>
#include "DBEn/DBEntityTestDB.h"
#include <vector>
using namespace std;

int main() {
    DBEntityTestDB dbEntity("../../122.db","");

    for(const auto& row :dbEntity.Test1.GetList() ) {
        std::cout<<row.Id<<" "<<row.Name<<std::endl;
    }
    std::vector<Test1> vectorTest;
    vectorTest.push_back(Test1 {5,"124"});

    dbEntity.Test1.InsertList(vectorTest);


    for(const auto& row :dbEntity.Test1.GetList() ) {
        std::cout<<row.Id<<" "<<row.Name<<std::endl;
    }
    // cout << "Hello world!" << endl;
    return 0;
}
