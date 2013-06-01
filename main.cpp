#include <iostream>
#include "src/Connection/DBConnection.h"
#include "src/tools/Log/LoggingSystem.h"
using namespace std;

int main() {
    Connection::DBConnection var;

    LoggingSystem * Log = LoggingSystem::GetLoggingSystem();

    Log->Write("Hello world!");
//    cout <<  << endl;
    return 0;
}
