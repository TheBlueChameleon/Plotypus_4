#include<sstream>

#include "scriptfragment.h"

namespace Plotypus
{
    std::string ScriptFragment::generateScriptFragment() const
    {
        std::ostringstream result;
        writeScriptFragment(result);
        return result.str();
    }
}
