#include "cleansheetfragment.h"


namespace Plotypus
{
    namespace SheetFragments
    {

        std::string CleanSheetFragment::generateCleanSheetOnScriptFragment() const
        {
            std::ostringstream result;

            result << "# " << std::string(76, '.') << " #\n";
            result << "# prepare empty page" << std::endl << std::endl;

            result << "unset border" << std::endl;
            result << "unset xtics"  << std::endl;
            result << "unset xlabel" << std::endl;
            result << "unset ytics"  << std::endl;
            result << "unset ylabel" << std::endl;

            result << std::endl;

            return result.str();
        }

        std::string CleanSheetFragment::generateCleanSheetOffScriptFragment() const
        {
            std::ostringstream result;

            result << "# " << std::string(76, '.') << " #\n";
            result << "# cleanup empty page commands" << std::endl << std::endl;

            result << "set border" << std::endl;
            result << "set xtics"  << std::endl;
            result << "set xlabel" << std::endl;
            result << "set ytics"  << std::endl;
            result << "set ylabel" << std::endl;

            return result.str();
        }
    }
}
