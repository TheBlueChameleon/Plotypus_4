#ifndef NAMEDTYPE_H
#define NAMEDTYPE_H

namespace Plotypus
{
    struct NamedType
    {
        virtual const std::string& getTypeName() const = 0;
    };
}
#endif // NAMEDTYPE_H
