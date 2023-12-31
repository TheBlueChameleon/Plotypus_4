#include "sheet.h"

namespace Plotypus
{
    void Sheet::writeScript(std::ostream& hFile) const
    {
        writeUserScriptBeforeSetup(hFile);
        writeScriptHead(hFile);

        writeUserScriptBeforeChildren(hFile);
        writeScriptData(hFile);
        writeScriptOverlays(hFile);

        writeScriptFooter(hFile);
        writeUserScriptCleanUp(hFile);
    }
}
