#ifndef PLOTYPUS_H
#define PLOTYPUS_H

#include "typesystem/enums.h"
#include "typesystem/constants.h"
#include "typesystem/errors.h"
#include "typesystem/concepts.h"
#include "typesystem/types.h"

#include "base/namedtype.h"
#include "base/nonassignable.h"
#include "base/scriptfragment.h"
#include "base/scriptable.h"
#include "base/serializable.h"

#include "base/collection/collection.h"
#include "base/collection/array.h"
#include "base/collection/fifo.h"
#include "base/collection/stdrangeutils.h"

#include "base/persistable/persistable.h"
#include "base/persistable/propagatingpersistable.h"
#include "base/persistable/defaultpersistable.h"
#include "base/persistable/defaultpropagatingpersistable.h"

#include "sheet/sheet.h"
#include "sheet/emptysheet.h"

#include "report/report.h"
#include "report/terminalinfoprovider/pdfcairo.h"
#include "report/terminalinfoprovider/terminalinfoprovider.h"

#endif // PLOTYPUS_H
