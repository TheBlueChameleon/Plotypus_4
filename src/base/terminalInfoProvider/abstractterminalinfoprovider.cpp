#include "abstractterminalinfoprovider.h"

namespace Plotypus
{
    AbstractTerminalInfoProvider::AbstractTerminalInfoProvider(const std::filesystem::__cxx11::path& fileCreatedByScript) :
        fileCreatedByScript(fileCreatedByScript)
    {

    }

    const std::filesystem::path& AbstractTerminalInfoProvider::getFileCreatedByScript() const
    {
        return fileCreatedByScript;
    }

    void AbstractTerminalInfoProvider::setFileCreatedByScript(const std::filesystem::path& newFileCreatedByScript)
    {
        fileCreatedByScript = newFileCreatedByScript;
    }

    void AbstractTerminalInfoProvider::reset()
    {
        fileCreatedByScript.clear();
    }

}
