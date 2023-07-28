#ifndef SCRIPTABLEIMPL_H
#define SCRIPTABLEIMPL_H

#include "base/groupedproperties/scriptfragment.h"

namespace Plotypus
{
    class UserCodeFragment : public ScriptFragment
    {
        protected:
            std::optional<std::string> userCode;

        public:
            UserCodeFragment() = default;

            std::optional<std::string> getUserCode() const;
            std::string getUserCodeOrDefault(const std::string& defaultValue) const;
            void setUserCode(const std::string& newOptions);
            void clearUserCode();

            // Fragment interface
            void reset();
            std::string generateScriptFragment() const;
    };
}

#endif // SCRIPTABLEIMPL_H