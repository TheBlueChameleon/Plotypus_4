#include "array.h"

#include "sheet/sheet.h"

namespace Plotypus
{
    template class Array<Sheet>;
    template class ArrayIterable<Sheet>;
    template class ArrayConstIterable<Sheet>;

    template class FiFo<Persistable>;
    template class FiFoIterable<Persistable>;
    template class FiFoConstIterable<Persistable>;
}
