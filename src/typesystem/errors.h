#ifndef ERRORS_H
#define ERRORS_H

#include <stdexcept>

namespace Plotypus
{
    class PlotypusError : public std::runtime_error
    {
        public :
            PlotypusError(const std::string& m);

            virtual void trigger() const;
            virtual PlotypusError* getDuplicate() const;
    };

#define PLOTYPUS_ERROR(ErrorClassName) \
    class ErrorClassName : public PlotypusError { \
        public : \
            ErrorClassName (const std::string & m) : PlotypusError(#ErrorClassName ": " + m) {} \
            virtual void trigger() const {throw *this;}; \
            virtual ErrorClassName* getDuplicate() const {return new ErrorClassName(this->what());} \
    }

    PLOTYPUS_ERROR(InvalidIndexError);
    PLOTYPUS_ERROR(InvalidArgumentError);
    PLOTYPUS_ERROR(InvalidTypeError);

    PLOTYPUS_ERROR(InvalidFilenameError);
    PLOTYPUS_ERROR(FileIOError);

    PLOTYPUS_ERROR(IncompleteDescritporError);

    PLOTYPUS_ERROR(UnsupportedOperationError);

    PLOTYPUS_ERROR(IncompatiblePlotStyle);
}

#endif // ERRORS_H
