#include <iostream>

#include "plotypus.h"

using namespace std;

int main()
{
    using namespace Plotypus;

    ValidationResult x, y;
    std::cout << "### EMPTY VALIDATION RESULT" << std::endl;
    std::cout << x << std::endl;

    x.addError<InvalidArgumentError>("Invalid Argument", "x");
    x.addError<IncompleteDescritporError>("Incomplete Descriptor", "x");
    std::cout << "### ITEMS IN VALIDATION RESULT" << std::endl;
    std::cout << x << std::endl;

    y.addError<InvalidArgumentError>("foo bar", "y");
    y.absorbValidationResult(x, "y");
    std::cout << "### SUBITEMS IN VALIDATION RESULT" << std::endl;
    std::cout << y << std::endl;

    std::cout << "### CAPTURED RESULT" << std::endl;
    std::cout << x << std::endl;
    return 0;

    Report report;
    //report.setChildFileNames();
    std::string script = report.getScriptString();

    std::cout << script << std::endl;
    std::cout << report.getPath() << std::endl;
    std::cout << report.getTerminal<TerminalInfo::PdfCairo>().getPath() << std::endl;

    std::ostringstream os;
    EmptySheet foo;
    foo.writeScript(os);
    return 0;
}
