#ifndef PERSISTABLE_H
#define PERSISTABLE_H

#include <optional>

#include "../typesystem/types.h"
#include "../base/validationresult.h"

namespace Plotypus
{
    struct Persistable
    {
        virtual std::ofstream getFileStream() = 0;
        virtual std::ostringstream getStringStream() = 0;

        virtual ValidationResult validateFilename() = 0;
        virtual void write(std::ostream& hFile) = 0;
    };
}

#endif // PERSISTABLE_H
