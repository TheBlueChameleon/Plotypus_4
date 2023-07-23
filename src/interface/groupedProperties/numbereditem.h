#ifndef NUMBEREDITEM_H
#define NUMBEREDITEM_H

#include "../baseProperties/mutable.h"

namespace Plotypus
{
    struct NumberedItem:
        public Mutable
    {
        virtual size_t getNumber() const = 0;
        virtual void setNumber(size_t number) = 0;
    };
}
#endif // NUMBEREDITEM_H
