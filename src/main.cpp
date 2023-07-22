#include <iostream>
#include "plotypus.h"

using namespace std;

int main()
{
    using namespace Plotypus;

    Report report;
    //report.setChildFileNames();
    std::string script = report.getScriptString();

    std::cout << script << std::endl;
    return 0;
}
