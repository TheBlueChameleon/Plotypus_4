#ifndef FRAGMENT_H
#define FRAGMENT_H

namespace Plotypus
{
    struct Fragment
    {
        virtual void reset() = 0;
        virtual std::string generateScriptFragment() const = 0;
    };
}
#endif // FRAGMENT_H
