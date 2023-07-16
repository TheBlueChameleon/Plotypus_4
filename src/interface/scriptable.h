#ifndef SCRIPTABLE_H
#define SCRIPTABLE_H

namespace Plotypus
{
    struct Scriptable
    {
        virtual void reset() = 0;

        virtual bool validateScript() = 0;
        virtual void writeScript(std::ostream& hFile) = 0;
    };
}

#endif // SCRIPTABLE_H
