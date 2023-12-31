#ifndef VALIDATIONRESULT_H
#define VALIDATIONRESULT_H

#include <list>

namespace Plotypus
{
    class ValidationResult
    {
        public:
            using ValidationResultElement = std::pair<PlotypusError*, std::list<std::string>>;
            const static ValidationResult SUCCESS;

        private:
            std::list<ValidationResultElement> results;

        public:
            ValidationResult() = default;
            ValidationResult(const ValidationResult& other);
            ValidationResult(ValidationResult&& other);

            // copy assignment (copy-and-swap idiom)
            ValidationResult& operator=(ValidationResult other);

            ~ValidationResult();

            template<ErrorType T>
            void addError(const std::string& message, const std::string& stackTraceElement);

            void absorbValidationResult(ValidationResult& subResult, const std::string& stackTraceElement);
            void absorbValidationResult(ValidationResult&& subResult, const std::string& stackTraceElement);

            const std::list<ValidationResultElement>& getResults() const;
            const std::optional<ValidationResultElement> getFirstResult() const;
            const std::list<std::string> getMessages() const;

            void trigger() const;

            operator bool() const;
            bool operator==(const ValidationResult& other) const = default;

            void writeValidationResults(std::ostream& stream) const;
            std::string getValidationReport() const;

            friend std::ostream& operator<<(std::ostream& os, const ValidationResult& validationResult);
    };
}

#include "validationresult.txx"

#endif // VALIDATIONRESULT_H
