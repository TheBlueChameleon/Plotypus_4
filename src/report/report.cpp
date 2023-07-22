#include <fstream>

#include "report.h"

namespace Plotypus
{
    bool Report::getSetUpdateChildFileNames() const
    {
        return autoSetChildFileNames;
    }

    void Report::setSetUpdateChildFileNames(const bool newSetUpdateChildFileNames)
    {
        autoSetChildFileNames = newSetUpdateChildFileNames;
    }

    void Report::setChildFileNames()
    {
        const auto scriptPath = getOutputPath(GeneratedFileType::Script);
        scriptPersistable.setPath(scriptPath);

        const auto reportPath = getOutputPath(GeneratedFileType::Report);
        outputPersistable.setPath(reportPath);
    }

    Persistable& Report::getScriptFile()
    {
        return scriptPersistable;
    }

    Persistable& Report::getOutputFile()
    {
        return outputPersistable;
    }

    void Report::compile()
    {
        if (autoSetChildFileNames)
        {
            setChildFileNames();
        }

        validateScript().trigger();

        auto hFile = scriptPersistable.getFileStream();
        writeScript(hFile);

        runScript();
    }

    void Report::runScript()
    {
        OutputPathProvider::reset();

        autoSetChildFileNames = true;
        outputPersistable.reset();
        scriptPersistable.reset();
    }

    void Report::reset()
    {

    }

    ValidationResult Report::validateScript()
    {
        if (!tip)
        {
            return ValidationResult::makeValidationResult<IncompleteDescritporError>("No TerminalInfoProvider was set");
        }

        // validation of scriptPersistable happens in getFileStream
        return outputPersistable.validate();
    }

    void Report::writeScript(std::ostream& hFile)
    {

    }
}
