#ifndef CLEANSHEETFRAGMENT_H
#define CLEANSHEETFRAGMENT_H

namespace Plotypus
{
    namespace SheetFragments
    {
        class CleanSheetFragment
        {
            public:
                CleanSheetFragment() = default;

                std::string generateCleanSheetOnScriptFragment() const;
                std::string generateCleanSheetOffScriptFragment() const;
        };
    }
}

#endif // CLEANSHEETFRAGMENT_H
