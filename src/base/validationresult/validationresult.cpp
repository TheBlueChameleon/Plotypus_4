#include <iostream>
#include <ranges>

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

    ValidationResult::ValidationResult(ValidationResult&& other)
    {
        results = other.results;
        other.results.clear();
    }

    ValidationResult::ValidationResult(const ValidationResult& other)
    {
        if (!other)
        {
            for (const auto& [errorPtr, stackTrace] : other.results)
            {
                results.push_back(std::make_pair(errorPtr->getDuplicate(), stackTrace));
            }
        }
    }

    ValidationResult& ValidationResult::operator=(ValidationResult other)
    {
        results = other.results;
        other.results.clear();
        return *this;
    }

    ValidationResult::~ValidationResult()
    {
        for (auto& result : results)
        {
            delete result.first;
        }
        results.clear();
    }

    void ValidationResult::absorbValidationResult(ValidationResult& subResult, const std::string& stackTraceElement)
    {
        for (auto& result : subResult.results)
        {
            result.second.push_front(stackTraceElement);
            results.push_back(std::move(result));
        }

        subResult.results.clear();
    }

    void ValidationResult::absorbValidationResult(ValidationResult&& subResult, const std::string& stackTraceElement)
    {
        absorbValidationResult(subResult, stackTraceElement);
    }

    const std::list<std::string> ValidationResult::getMessages() const
    {
        std::list<std::string> messages;

        std::transform(results.begin(), results.end(),
                       std::back_inserter(messages),
                       [] (const ValidationResultElement& result)
        {
            return result.first->what();
        }
                      );

        return messages;
    }

    const std::list<ValidationResult::ValidationResultElement>& ValidationResult::getResults() const
    {
        return results;
    }

    const std::optional<ValidationResult::ValidationResultElement> ValidationResult::getFirstResult() const
    {
        if (results.empty())
        {
            return std::optional<ValidationResult::ValidationResultElement>();
        }
        else
        {
            return std::optional(results.front());
        }
    }

    void ValidationResult::trigger() const
    {
        if (!results.empty())
        {
            const auto* firstError = results.front().first;
            firstError->trigger();
        }
    }

    ValidationResult::operator bool() const
    {
        return results.empty();
    }

    bool ValidationResult::operator==(const ValidationResult& other) const
    {
        return this->results == other.results;
    }

    void ValidationResult::writeValidationResults(std::ostream& stream) const
    {
        if (*this)
        {
            stream << "--- NO ERRORS ---" << std::endl;
        }
        else
        {
            for (const auto& [error, stackTrace] : results)
            {
                stream << error->what() << std::endl;
                auto view = std::ranges::reverse_view(stackTrace);
                for (size_t indent = 0; const auto& element: view)
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
