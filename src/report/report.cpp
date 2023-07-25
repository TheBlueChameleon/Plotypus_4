#include <fstream>
#include <iostream>

#include "../interface/terminalinfoprovider.h"

#include "report.h"
#include "terminalinfoprovider/pdfcairo.h"

namespace Plotypus
{
    Report::Report()
    {
        installTerminal<TerminalInfo::PdfCairo>();

        const auto scriptPath = getOutputPath(GeneratedFileType::Script);
        scriptFile.setPath(scriptPath);
    }

    bool Report::getPropagateUpdateChildFileNames() const
    {
        return scriptFile.getPropagateUpdateChildFileNames();
    }

    void Report::setPropagateUpdateChildFileNames(const bool newPropagateUpdateChildFileNames)
    {
        scriptFile.setPropagateUpdateChildFileNames(newPropagateUpdateChildFileNames);
    }

    bool Report::getAllowNullPath() const
    {
        return scriptFile.getAllowNullPath();
    }

    void Report::setAllowNullPath(bool newAllowNullPath)
    {
        scriptFile.setAllowNullPath(newAllowNullPath);
    }

    void Report::setChildFileNames()
    {
        const auto scriptPath = getOutputPath(GeneratedFileType::Script);
        scriptFile.setPath(scriptPath);

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
                    if (c == 'f') {result << scriptFile.getPath();}
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

        setPropagateUpdateChildFileNames(true);

        scriptFile.reset();
        sheets.clear();
    }

    ValidationResult Report::validate() const
    {
        // *INDENT-OFF*
        if (!tip) {return ValidationResult::makeValidationResult<IncompleteDescritporError>("No TerminalInfoProvider was set");}

        ValidationResult validation = tip->validate();
        if (!validation) {return validation;}

        validation = scriptFile.validate();
        if (!validation) {return validation;}
        // *INDENT-ON*

        return ValidationResult::SUCCESS;
    }

    void Report::writeScript(std::ostream& hFile)
    {
        writeUserScriptBeforeSetup(hFile);
        tip->writeScript(hFile);

        writeUserScriptBeforeChildren(hFile);
        // sheets

        writeUserScriptCleanUp(hFile);
    }

    const std::filesystem::path& Report::getPath() const
    {
        return scriptFile.getPath();
    }

    void Report::setPath(const std::filesystem::path& newPath)
    {
        scriptFile.setPath(newPath);
    }

    bool Report::getMakeDirectories() const
    {
        return scriptFile.getMakeDirectories();
    }

    void Report::setMakeDirectories(bool newMakeDirectories)
    {
        scriptFile.setMakeDirectories(newMakeDirectories);
    }

    bool Report::getOverwrite() const
    {
        return scriptFile.getOverwrite();
    }

    void Report::setOverwrite(bool newOverwrite)
    {
        scriptFile.setOverwrite(newOverwrite);
    }

    std::ofstream Report::getFileStream() const
    {
        return scriptFile.getFileStream();
    }

    std::ostringstream Report::getStringStream()
    {
        return scriptFile.getStringStream();
    }

    std::optional<std::string> Report::getUserScriptBeforeSetup() const
    {
        return userScripts.getUserScriptBeforeSetup();
    }

    void Report::setUserScriptBeforeSetup(const std::string& newUserScriptBeforeSetup)
    {
        userScripts.setUserScriptBeforeSetup(newUserScriptBeforeSetup);
    }

    std::optional<std::string> Report::getUserScriptBeforeChildren() const
    {
        return userScripts.getUserScriptBeforeChildren();
    }

    void Report::setUserScriptBeforeChildren(const std::string& newUserScriptBeforeChildren)
    {
        userScripts.setUserScriptBeforeChildren(newUserScriptBeforeChildren);
    }

    std::optional<std::string> Report::getUserScriptCleanUp() const
    {
        return userScripts.getUserScriptCleanUp();
    }

    void Report::setUserScriptCleanUp(const std::string& newUserScriptCleanUp)
    {
        userScripts.setUserScriptCleanUp(newUserScriptCleanUp);
    }

    void Report::writeUserScriptBeforeSetup(std::ostream& hFile)
    {
        userScripts.writeUserScriptBeforeSetup(hFile);
    }

    void Report::writeUserScriptBeforeChildren(std::ostream& hFile)
    {
        userScripts.writeUserScriptBeforeChildren(hFile);
    }

    void Report::writeUserScriptCleanUp(std::ostream& hFile)
    {
        userScripts.writeUserScriptCleanUp(hFile);
    }
}
