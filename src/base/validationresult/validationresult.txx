#include "validationresult.h"

namespace Plotypus
{
    template<ErrorType T>
    ValidationResult::ValidationResult(const T& error)
    {
        this->error = std::optional<T>(error);
    }


    template<ErrorType T>
    ValidationResult ValidationResult::makeValidationResult(const std::optional<std::string> message)
    {
        if (message.has_value())
        {
            return ValidationResult(T(message.value()));
        }
        else
        {
            return ValidationResult();
        }
    }
}
