#include <fstream>
#include <iostream>

#include "../interface/terminalInfoProvider.h"

#include "report.h"
#include "terminalInfoProvider/pdfcairo.h"

#include "../base/util.h"

namespace Plotypus
{
    Report::Report() :
        path(getOutputPath(GeneratedFileType::Script))
    {
        installTerminal<TerminalInfo::PdfCairo>();
    }

    bool Report::getAutoUpdateChildFileNames() const
    {
        return autoUpdateChildFileNames;
    }

    void Report::setAutoUpdateChildFileNames(const bool newSetUpdateChildFileNames)
    {
        autoUpdateChildFileNames = newSetUpdateChildFileNames;
    }

    void Report::setChildFileNames()
    {
        const auto scriptPath = getOutputPath(GeneratedFileType::Script);
        path = scriptPath;

        if (tip)
        {
            const auto reportPath = getOutputPath(GeneratedFileType::Report);
            tip->setPath(reportPath);
        }
    }

    const std::string& Report::getRunCommand() const
    {
        return runCommand;
    }

    void Report::setRunCommand(const std::string& newRunCommand)
    {
        runCommand = newRunCommand;
    }

    std::string Report::getParsedRunCommand() const
    {
        std::stringstream result;

        bool escapeMode = false;
        for (const auto c : runCommand)
        {
            if (c != '$')
            {
                result << c;
            }
            else
            {
                if (escapeMode)
                {
                    // *INDENT-OFF*
                    if (c == 'f') {result << path;}
                    else          {result << c;}
                    escapeMode = false;
                    // *INDENT-ON*
                }
                else
                {
                    escapeMode = true;
                }
            }
        }

        return result.str();
    }

    void Report::compile()
    {
        if (autoUpdateChildFileNames)
        {
            setChildFileNames();
        }
        writeScript();
        runScript();
    }

    void Report::writeScript()
    {
        validate().trigger();
        auto hFile = getFileStream();
        writeScript(hFile);
    }

    void Report::runScript()
    {
        const std::string runCommand = getParsedRunCommand();
        const int error = std::system(runCommand.data());

        if (error)
        {
            std::cerr << "gnuplot did not succeed. Error code: " << error << std::endl;
        }
    }

    std::string Report::getScriptString()
    {
        validate().trigger();
        auto buffer = getStringStream();
        writeScript(buffer);

        return buffer.str();
    }

    void Report::reset()
    {
        OutputPathProvider::reset();

        if (tip)
        {
            tip->reset();
        }

        runCommand = "gnuplot $f";

        autoUpdateChildFileNames = true;

        Util::resetPersistable(*this);
    }

    ValidationResult Report::validate() const
    {
        // *INDENT-OFF*
        if (!tip) {return ValidationResult::makeValidationResult<IncompleteDescritporError>("No TerminalInfoProvider was set");}

        ValidationResult validation = tip->validate();
        if (!validation) {return validation;}

        validation = Util::validatePersistable(*this);
        if (!validation) {return validation;}
        // *INDENT-ON*

        return ValidationResult::SUCCESS;
    }

    void Report::writeScript(std::ostream& hFile)
    {
        tip->writeScript(hFile);
    }

    const std::filesystem::path& Report::getPath() const
    {
        return path;
    }

    void Report::setPath(const std::filesystem::path& newPath)
    {
        path = newPath;
    }

    bool Report::getMakeDirectories() const
    {
        return makeDirectories;
    }

    void Report::setMakeDirectories(bool newMakeDirectories)
    {
        makeDirectories = newMakeDirectories;
    }

    bool Report::getOverwrite() const
    {
        return overwrite;
    }

    void Report::setOverwrite(bool newOverwrite)
    {
        overwrite = newOverwrite;
    }

    std::ofstream Report::getFileStream() const
    {
        return Util::getFileStream(path);
    }

    std::ostringstream Report::getStringStream()
    {
        return Util::getStringStream();
    }
}
