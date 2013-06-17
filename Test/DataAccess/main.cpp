#include <iostream>
#include "DBEn/DBEntityTestDB.h"
#include <vector>
using namespace std;

int main() {
    DBEntityTestDB dbEntity("../../TestDB.db","");

    for(const auto& row :dbEntity.Test1.GetList() ) {
        std::cout<<row.Id<<" "<<row.Name<<std::endl;
    }


    std::vector<Test1> vectorTest;
    vectorTest.push_back(Test1 {2,"124"});
    vectorTest.push_back(Test1 {3,"124"});
    vectorTest.push_back(Test1 {4,"124"});
    vectorTest.push_back(Test1 {5,"124"});
    vectorTest.push_back(Test1 {6,"124"});
    vectorTest.push_back(Test1 {7,"124"});
    vectorTest.push_back(Test1 {8,"124"});
    vectorTest.push_back(Test1 {9,"124"});
    vectorTest.push_back(Test1 {10,"124"});
    dbEntity.Test1.InsertList(vectorTest);


    for(const auto& row :dbEntity.Test1.GetList(1,1) ) {
        std::cout<<row.Id<<" "<<row.Name<<std::endl;
    }
    // cout << "Hello world!" << endl;
    return 0;
}
