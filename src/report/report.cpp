#include <fstream>
#include <iostream>

#include "terminalinfoprovider/terminalinfoprovider.h"

#include "report.h"
#include "terminalinfoprovider/pdfcairo.h"

namespace Plotypus
{
    template TerminalInfo::PdfCairo& Report::installTerminal();
    template TerminalInfo::PdfCairo& Report::getTerminal();

    template void Report::addSubscriber<DefaultPersistable_SP>(DefaultPersistable_SP& subscriber);
    template void Report::addSubscriber<DefaultPropagatingPersistable_SP>(DefaultPropagatingPersistable_SP& subscriber);

    Report::Report()
    {
        scriptFile.setPath("report.pdf");
        installTerminal<TerminalInfo::PdfCairo>();
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

    std::filesystem::path Report::getDerivedPath(const std::string& extension, std::optional<std::string> infix)
    {
        return scriptFile.getDerivedPath(extension, infix);
    }

    void Report::updateChildFileNames()
    {
        scriptFile.updateChildFileNames();
    }

    void Report::addSubscriber(std::shared_ptr<Persistable>& subscriber)
    {
        scriptFile.addSubscriber(subscriber);
    }

    void Report::replaceSubscriber(std::shared_ptr<Persistable>& oldSubscriber, std::shared_ptr<Persistable>& newSubscriber)
    {
        scriptFile.replaceSubscriber(oldSubscriber, newSubscriber);
    }

    Collection<Persistable>& Report::getSubscribers()
    {
        return scriptFile.getSubscribers();
    }

    const Collection<Persistable>& Report::getSubscribers() const
    {
        return scriptFile.getSubscribers();
    }

    std::string Report::getInstanceName() const
    {
        return getTypeName();
    }

    std::string Report::getTypeName()
    {
        return "Report";
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
        for (const char c : runCommand)
        {
            // *INDENT-OFF*
            if (c != '$') {result << c;}
            else {
                if (escapeMode) {
                    if (c == 'f') {result << scriptFile.getPath();}
                    else          {result << c;}
                    escapeMode = false;
                }
                else {escapeMode = true;}
            }
            // *INDENT-ON*
        }

        return result.str();
    }

    void Report::compile() const
    {
        writeScript();
        runScript();
    }

    void Report::writeScript() const
    {
        validate().trigger();
        auto hFile = getFileStream();
        writeScript(hFile);
    }

    void Report::runScript() const
    {
        const std::string runCommand = getParsedRunCommand();
        const int error = std::system(runCommand.data());

        if (error)
        {
            std::cerr << "gnuplot did not succeed. Error code: " << error << std::endl;
        }
    }

    std::string Report::getScriptString() const
    {
        validate().trigger();
        auto buffer = getStringStream();
        writeScript(buffer);
        return buffer.str();
    }

    void Report::reset()
    {
        if (tip)
        {
            tip->reset();
        }

        scriptFile.reset();
        userScripts.reset();
        sheets.clear();
        runCommand = "gnuplot $f";
    }

    ValidationResult Report::validate() const
    {
        ValidationResult result;
        const std::string typeName = getTypeName();

        if (!tip)
        {
            result.addError<IncompleteDescritporError>("No TerminalInfoProvider was set", typeName);
            return result;
        }

        result.absorbValidationResult(tip->validate(), typeName);
        result.absorbValidationResult(scriptFile.validate(), typeName);

        for (auto& sheet : sheets)
        {
            result.absorbValidationResult(sheet.validate(), typeName);
        }

        return result;
    }

    void Report::writeScript(std::ostream& hFile) const
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

    std::ostringstream Report::getStringStream() const
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

    void Report::writeUserScriptBeforeSetup(std::ostream& hFile) const
    {
        userScripts.writeUserScriptBeforeSetup(hFile);
    }

    void Report::writeUserScriptBeforeChildren(std::ostream& hFile) const
    {
        userScripts.writeUserScriptBeforeChildren(hFile);
    }

    void Report::writeUserScriptCleanUp(std::ostream& hFile) const
    {
        userScripts.writeUserScriptCleanUp(hFile);
    }
}
