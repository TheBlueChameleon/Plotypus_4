#include <fstream>

#include "emptysheet.h"

namespace Plotypus
{
    ValidationResult Plotypus::EmptySheet::validate() const
    {
        ValidationResult validation = file.validate();
        if (!validation)
        {
            return validation;
        }

        return validation;
    }

    void EmptySheet::reset()
    {
        number.reset();
        file.reset();
        userCode.reset();
    }

    const std::filesystem::path& EmptySheet::getPath() const
    {
        return file.getPath();
    }

    void EmptySheet::setPath(const std::filesystem::path& newPath)
    {
        file.setPath(newPath);
    }

    bool EmptySheet::getMakeDirectories() const
    {
        return file.getMakeDirectories();
    }

    void EmptySheet::setMakeDirectories(bool newMakeDirectories)
    {
        file.setMakeDirectories(newMakeDirectories);
    }

    bool EmptySheet::getOverwrite() const
    {
        return file.getOverwrite();
    }

    void EmptySheet::setOverwrite(bool newOverwrite)
    {
        file.setOverwrite(newOverwrite);
    }

    bool EmptySheet::getAllowNullPath() const
    {
        return file.getAllowNullPath();
    }

    void EmptySheet::setAllowNullPath(bool newAllowNullPath)
    {
        file.setAllowNullPath(newAllowNullPath);
    }

    std::ofstream EmptySheet::getFileStream() const
    {
        return file.getFileStream();
    }

    std::ostringstream EmptySheet::getStringStream()
    {
        return file.getStringStream();
    }

    void EmptySheet::writeScriptHead(std::ostream& hFile) const
    {
        hFile << SheetFragments::CleanSheetFragment::generateCleanSheetOnScriptFragment();

        // set origin x, y
        // set size w, h

        hFile << SheetFragments::FontFragment::generateScriptFragment();
        hFile << SheetFragments::TitleFragment::generateScriptFragment();
    }

    void EmptySheet::writeScriptData(std::ostream& hFile) const
    {
        hFile << "plot [0:1][1:0] 1/0 t\"\"  # dummy plot for empty page" << std::endl << std::endl;
    }

    void EmptySheet::writeScriptOverlays(std::ostream& hFile) const
    {

    }

    void EmptySheet::writeScriptFooter(std::ostream& hFile) const
    {
        hFile << SheetFragments::CleanSheetFragment::generateCleanSheetOffScriptFragment();
    }

    size_t EmptySheet::getNumber() const
    {
        return number.getNumber();
    }

    void EmptySheet::setNumber(size_t newNumber)
    {
        number.setNumber(newNumber);
    }

    std::optional<std::string> EmptySheet::getUserScriptBeforeSetup() const
    {
        return userCode.getUserScriptBeforeSetup();
    }

    void EmptySheet::setUserScriptBeforeSetup(const std::string& newUserScriptBeforeSetup)
    {
        userCode.setUserScriptBeforeSetup(newUserScriptBeforeSetup);
    }

    std::optional<std::string> EmptySheet::getUserScriptBeforeChildren() const
    {
        return userCode.getUserScriptBeforeChildren();
    }

    void EmptySheet::setUserScriptBeforeChildren(const std::string& newUserScriptBeforeChildren)
    {
        userCode.setUserScriptBeforeChildren(newUserScriptBeforeChildren);
    }

    std::optional<std::string> EmptySheet::getUserScriptCleanUp() const
    {
        return userCode.getUserScriptCleanUp();
    }

    void EmptySheet::setUserScriptCleanUp(const std::string& newUserScriptCleanUp)
    {
        userCode.setUserScriptCleanUp(newUserScriptCleanUp);
    }

    void EmptySheet::writeUserScriptBeforeSetup(std::ostream& hFile)
    {
        userCode.writeUserScriptBeforeSetup(hFile);
    }

    void EmptySheet::writeUserScriptBeforeChildren(std::ostream& hFile)
    {
        userCode.writeUserScriptBeforeChildren(hFile);
    }

    void EmptySheet::writeUserScriptCleanUp(std::ostream& hFile)
    {
        userCode.writeUserScriptCleanUp(hFile);
    }
}
