#ifndef ERRORS_H
#define ERRORS_H

#include <stdexcept>

namespace Plotypus
{
    class PlotypusError : public std::runtime_error
    {
        public :
            PlotypusError (const std::string& m);

            bool operator==(const PlotypusError& other) const;
    };

#define PLOTYPUS_ERROR(ErrorClassName) \
    class ErrorClassName : public PlotypusError { \
        public : ErrorClassName (const std::string & m) : PlotypusError(m) {} \
    }

    PLOTYPUS_ERROR(InvalidFilenameError);
    PLOTYPUS_ERROR(InvalidIndexError);
    PLOTYPUS_ERROR(InvalidArgumentError);

    PLOTYPUS_ERROR(FileIOError);

    PLOTYPUS_ERROR(IncompleteDescritporError);

    PLOTYPUS_ERROR(UnsupportedOperationError);

    PLOTYPUS_ERROR(IncompatiblePlotStyle);
}

#endif // ERRORS_H
