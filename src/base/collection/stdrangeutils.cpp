#include <list>

#include "stdrangeutils.h"
#include "base/persistable/persistable.h"

namespace Plotypus
{
    using Persistable_SP = std::shared_ptr<Persistable>;
    template void findAndReplace(std::list<Persistable_SP>& collection, const Persistable_SP& oldValue, const Persistable_SP& newValue);
}
