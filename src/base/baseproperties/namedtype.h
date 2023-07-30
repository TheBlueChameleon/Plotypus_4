#ifndef NAMEDTYPE_H
#define NAMEDTYPE_H

namespace Plotypus
{
    struct NamedType
    {
        NamedType() = default;

        virtual std::string getInstanceName() const = 0;
    };

}
#endif // NAMEDTYPE_H
