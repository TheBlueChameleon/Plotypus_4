#ifndef NAMEDTYPE_H
#define NAMEDTYPE_H

namespace Plotypus
{
    struct NamedType
    {
        static const std::string getTypeName()
        {
            return "(unnamed Type)";
        };
    };
}
#endif // NAMEDTYPE_H
