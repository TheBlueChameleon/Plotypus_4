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

    ValidationResult::~ValidationResult()
    {
        for (auto& error : errors)
        {
            delete error.first;
        }
    }

    void ValidationResult::absorbValidationResult(ValidationResult& subResult, const std::string& stackTraceElement)
    {
        for (auto& error : subResult.errors)
        {
            error.second.push_front(stackTraceElement);
            errors.push_back(std::move(error));
        }

        subResult.errors.clear();
    }

    const std::list<ValidationResult::ValidationResultElement>& ValidationResult::getErrors() const
    {
        return errors;
    }

    const std::optional<ValidationResult::ValidationResultElement> ValidationResult::getFirstError() const
    {
        if (errors.empty())
        {
            return std::optional<ValidationResult::ValidationResultElement>();
        }
        else
        {
            return std::optional(errors.front());
        }
    }

    void ValidationResult::trigger() const
    {
        if (!errors.empty())
        {
            const auto& x = errors.front().first;
            throw* x;
        }
    }

    ValidationResult::operator bool() const
    {
        return errors.empty();
    }

    bool ValidationResult::operator==(const ValidationResult& other) const
    {
        return this->errors == other.errors;
    }

    void ValidationResult::writeValidationResults(std::ostream& stream) const
    {
        if (*this)
        {
            stream << "NO ERRORS" << std::endl;
        }
        else
        {
            for (const auto& [error, stackTrace] : errors)
            {
                stream << "ERROR: " << error->what() << std::endl;
                for (size_t indent = 0; const auto& element: stackTrace)
                {
                    ++indent;
                    stream << std::string(indent, ' ') << "from " << element << std::endl;
                }
            }
        }
    }

    std::string ValidationResult::getValidationReport() const
    {
        std::stringstream buffer;
        writeValidationResults(buffer);
        return buffer.str();
    }

    std::ostream& operator<<(std::ostream& os, const ValidationResult& validationResult)
    {
        validationResult.writeValidationResults(os);
        return os;
    }
}
