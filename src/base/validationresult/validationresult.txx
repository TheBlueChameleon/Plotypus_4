#include "validationresult.h"

namespace Plotypus
{
    template<ErrorType T>
    void ValidationResult::addError(const std::string& message, const std::string& stackTraceElement)
    {
        ValidationResultElement element = std::make_pair(
                                              new T(message),
                                              std::list<std::string>(1, stackTraceElement)
                                          );
        results.push_back(std::move(element));
    }
}
