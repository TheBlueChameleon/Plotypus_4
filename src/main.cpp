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
    std::cout << report.getPath() << std::endl;
    std::cout << report.getTerminal<TerminalInfo::PdfCairo>().getPath() << std::endl;
    return 0;
}
