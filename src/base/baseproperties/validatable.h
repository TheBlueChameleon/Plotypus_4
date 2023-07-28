#ifndef VALIDATABLE_H
#define VALIDATABLE_H

#include "base/validationresult/validationresult.h"

namespace Plotypus
{
    struct Validatable
    {
        virtual ValidationResult validate() const = 0;
    };
}
#endif // VALIDATABLE_H
