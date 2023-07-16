#ifndef SCRIPTABLEIMPL_H
#define SCRIPTABLEIMPL_H

#include "../interface/customizable.h"

namespace Plotypus
{
    class CustomizableImpl : public Customizable
    {
        protected:
            std::optional<std::string> options;

        public:
            CustomizableImpl() = default;

            // Customizable interface
            virtual void reset();

            std::optional<std::string> getOptions() const;
            std::string getOptionsOrDefault(const std::string& defaultValue) const;
            void setOptions(const std::string& newOptions);
            void clearOptions();

            // Fragment interface
            std::string generateScriptFragment() const;
    };
}

#endif // SCRIPTABLEIMPL_H
