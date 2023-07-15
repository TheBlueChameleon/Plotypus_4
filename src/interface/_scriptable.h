#ifndef SCRIPTABLE_H
#define SCRIPTABLE_H

#include <optional>
#include <ostream>

namespace Plotypus
{
    class Scriptable
    {
        protected:
            std::optional<std::string> options;

        public:
            std::string getOptions() const;
            Scriptable& setOptions(const std::string& newOptions);
            Scriptable& clearOptions();

            virtual void writeScript(std::ostream& hFile) const = 0;
    };

}

#endif // SCRIPTABLE_H
