#ifndef PLOTYPUS_H
#define PLOTYPUS_H

#include "typesystem/enums.h"
#include "typesystem/constants.h"
#include "typesystem/errors.h"
#include "typesystem/concepts.h"
#include "typesystem/types.h"

#include "interface/baseProperties/collection.h"
#include "interface/baseProperties/namedtype.h"
#include "interface/baseProperties/nonAssignable.h"
#include "interface/baseProperties/persistable.h"

#include "interface/baseProperties/defaultImpl/defaultcollection.h"
#include "interface/baseProperties/defaultImpl/defaultpersistable.h"

#include "interface/groupedProperties/scriptfragment.h"
#include "interface/groupedProperties/scriptable.h"
#include "interface/groupedProperties/serializable.h"

#include "interface/terminalInfoProvider.h"
#include "interface/sheet.h"

#include "report/report.h"
#include "report/terminalInfoProvider/pdfcairo.h"

#include "sheet/emptysheet.h"

#endif // PLOTYPUS_H
