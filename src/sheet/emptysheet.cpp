#include <fstream>

#include "emptysheet.h"

namespace Plotypus
{
    EmptySheet::EmptySheet()
    {
        file = std::make_shared<DefaultPersistable>();
    }

    std::string EmptySheet::getInstanceName() const
    {
        return getTypeName() + getNumberText();
    }

    std::string EmptySheet::getTypeName()
    {
        return "EmptySheet";
    }

    ValidationResult Plotypus::EmptySheet::validate() const
    {
        ValidationResult result;
        result.absorbValidationResult(file->validate(), getInstanceName());

        return result;
    }

    void EmptySheet::reset()
    {
        TitleFragment::reset();
        FontFragment::reset();

        DefaultNumberedItem::reset();
        DefaultUserScriptInjectable::reset();

        file.reset();
    }

    const std::filesystem::path& EmptySheet::getPath() const
    {
        return file->getPath();
    }

    void EmptySheet::setPath(const std::filesystem::path& newPath)
    {
        file->setPath(newPath);
    }

    bool EmptySheet::getMakeDirectories() const
    {
        return file->getMakeDirectories();
    }

    void EmptySheet::setMakeDirectories(bool newMakeDirectories)
    {
        file->setMakeDirectories(newMakeDirectories);
    }

    bool EmptySheet::getOverwrite() const
    {
        return file->getOverwrite();
    }

    void EmptySheet::setOverwrite(bool newOverwrite)
    {
        file->setOverwrite(newOverwrite);
    }

    bool EmptySheet::getAllowNullPath() const
    {
        return file->getAllowNullPath();
    }

    void EmptySheet::setAllowNullPath(bool newAllowNullPath)
    {
        file->setAllowNullPath(newAllowNullPath);
    }

    std::ofstream EmptySheet::getFileStream() const
    {
        return file->getFileStream();
    }

    std::ostringstream EmptySheet::getStringStream() const
    {
        return file->getStringStream();
    }

    void EmptySheet::writeScriptHead(std::ostream& hFile) const
    {
        hFile << SheetFragments::CleanSheetFragment::generateCleanSheetOnScriptFragment();

        // TODO set origin x, y
        // TODO set size w, h

        SheetFragments::FontFragment::writeScriptFragment(hFile);
        SheetFragments::TitleFragment::writeScriptFragment(hFile);
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

    std::optional<std::string> EmptySheet::getUserScriptBeforeSetup() const
    {
        return DefaultUserScriptInjectable::getUserScriptBeforeSetup();
    }

    void EmptySheet::setUserScriptBeforeSetup(const std::string& newUserScriptBeforeSetup)
    {
        DefaultUserScriptInjectable::setUserScriptBeforeSetup(newUserScriptBeforeSetup);
    }

    std::optional<std::string> EmptySheet::getUserScriptBeforeChildren() const
    {
        return DefaultUserScriptInjectable::getUserScriptBeforeChildren();
    }

    void EmptySheet::setUserScriptBeforeChildren(const std::string& newUserScriptBeforeChildren)
    {
        DefaultUserScriptInjectable::setUserScriptBeforeChildren(newUserScriptBeforeChildren);
    }

    std::optional<std::string> EmptySheet::getUserScriptCleanUp() const
    {
        return DefaultUserScriptInjectable::getUserScriptCleanUp();
    }

    void EmptySheet::setUserScriptCleanUp(const std::string& newUserScriptCleanUp)
    {
        DefaultUserScriptInjectable::setUserScriptCleanUp(newUserScriptCleanUp);
    }

    void EmptySheet::writeUserScriptBeforeSetup(std::ostream& hFile) const
    {
        DefaultUserScriptInjectable::writeUserScriptBeforeSetup(hFile);
    }

    void EmptySheet::writeUserScriptBeforeChildren(std::ostream& hFile) const
    {
        DefaultUserScriptInjectable::writeUserScriptBeforeChildren(hFile);
    }

    void EmptySheet::writeUserScriptCleanUp(std::ostream& hFile) const
    {
        DefaultUserScriptInjectable::writeUserScriptCleanUp(hFile);
    }

    size_t EmptySheet::getNumber() const
    {
        return DefaultNumberedItem::getNumber();
    }

    void EmptySheet::setNumber(size_t newNumber)
    {
        DefaultNumberedItem::setNumber(newNumber);
    }

    std::string EmptySheet::getNumberText() const
    {
        return DefaultNumberedItem::getNumberText();
    }
}
