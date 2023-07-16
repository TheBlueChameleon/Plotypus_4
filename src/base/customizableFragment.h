#ifndef SCRIPTABLEIMPL_H
#define SCRIPTABLEIMPL_H

#include "../interface/fragment.h"

namespace Plotypus
{
    class CustomizableFragment : public Fragment
    {
        protected:
            std::optional<std::string> options;

        public:
            CustomizableFragment() = default;

            std::optional<std::string> getOptions() const;
            std::string getOptionsOrDefault(const std::string& defaultValue) const;
            void setOptions(const std::string& newOptions);
            void clearOptions();

            // Fragment interface
            void reset();
            std::string generateScriptFragment() const;
    };
}

#endif // SCRIPTABLEIMPL_H
