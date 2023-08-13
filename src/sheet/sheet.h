#ifndef SHEET_H
#define SHEET_H

#include "base/scriptable.h"

#include "base/persistable/persistable.h"
#include "base/numbereditem/numbereditem.h"
#include "base/userscriptinjectable/userscriptinjectable.h"

namespace Plotypus
{
    struct Sheet:
        public virtual NamedType,
        public virtual Scriptable,
        public virtual Persistable,
        public virtual NumberedItem,
        public virtual UserScriptInjectable
    {
        virtual void writeScript(std::ostream& hFile) const;

        virtual void writeScriptHead(std::ostream& hFile) const = 0;
        virtual void writeScriptData(std::ostream& hFile) const = 0;
        virtual void writeScriptOverlays(std::ostream& hFile) const = 0;
        virtual void writeScriptFooter(std::ostream& hFile) const = 0;
    };
}
#endif // SHEET_H
