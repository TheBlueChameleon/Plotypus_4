#include "validationresult.h"

namespace Plotypus
{
    // ====================================================================== //
    // static vars
    const ValidationResult ValidationResult::SUCCESS = ValidationResult();

    // ====================================================================== //
    // template instatiations

    //template ValidationResult ValidationResult::makeValidationResult<InvalidFilenameError>(const std::optional<std::string> message);

    // ====================================================================== //
    // proper code

    const PlotypusError& ValidationResult::getError() const
    {
        if (error.has_value())
        {
            return error.value();
        }
        else
        {
            throw UnsupportedOperationError("No error to get from this ValidationResult.");
        }
    }

    void ValidationResult::trigger() const
    {
        if(error.has_value())
        {
            throw error.value();
        }
    }

    ValidationResult::operator bool() const
    {
        return !error.has_value();
    }

    bool ValidationResult::operator==(const ValidationResult& other) const
    {
        if (*this && other) // both validateD ok
        {
            return true;
        }
        else if (bool(*this) != bool(other)) // one but not both validated ok
        {
            return false;
        }
        else
        {
            // both validate not ok
            const auto& thisError = this->getError();
            const auto& otherError = other.getError();

            return thisError == otherError;
        }
    }


}
