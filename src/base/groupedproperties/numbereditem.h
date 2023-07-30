#ifndef NUMBEREDITEM_H
#define NUMBEREDITEM_H

#include "base/baseproperties/mutable.h"

namespace Plotypus
{
    struct NumberedItem:
        public Mutable
    {
        virtual size_t getNumber() const = 0;
        virtual void setNumber(size_t number) = 0;
        virtual std::string getNumberText() const = 0;
    };
}
#endif // NUMBEREDITEM_H
