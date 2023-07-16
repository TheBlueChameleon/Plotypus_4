#include "validationresult.h"

namespace Plotypus
{
    template<typename T>
    requires Derivative<T, PlotypusError>
    ValidationResult::ValidationResult(const T& error)
    {
        this->error = std::optional<T>(error);
    }


    template<typename T>
    requires Derivative<T, PlotypusError>
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
