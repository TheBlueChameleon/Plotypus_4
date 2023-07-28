#ifndef SHEET_H
#define SHEET_H

#include "base/baseproperties/persistable.h"

#include "base/groupedproperties/numbereditem.h"
#include "base/groupedproperties/scriptable.h"
#include "base/groupedproperties/userscriptinjectable.h"

namespace Plotypus
{
    struct Sheet:
        public Scriptable,
        public Persistable,
        public NumberedItem,
        public UserScriptInjectable
    {
        virtual void writeScript(std::ostream& hFile) const;

        virtual void writeScriptHead    (std::ostream& hFile) const = 0;
        virtual void writeScriptData    (std::ostream& hFile) const = 0;
        virtual void writeScriptOverlays(std::ostream& hFile) const = 0;
        virtual void writeScriptFooter  (std::ostream& hFile) const = 0;
    };
}
#endif // SHEET_H
