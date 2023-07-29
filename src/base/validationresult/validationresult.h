#ifndef VALIDATIONRESULT_H
#define VALIDATIONRESULT_H

#include "base/baseproperties/collection/fifo.h"

namespace Plotypus
{
    class ValidationResult
    {
        public:
            using ValidationResultElement = std::pair<PlotypusError*, std::list<std::string>>;
            const static ValidationResult SUCCESS;

        private:
            std::list<ValidationResultElement> errors;

        public:
            ValidationResult() = default;
            ~ValidationResult();

            template<ErrorType T>
            void addError(const std::string& message, const std::string& stackTraceElement);

            void absorbValidationResult(ValidationResult& subResult, const std::string& stackTraceElement);

            const std::list<ValidationResultElement>& getErrors() const;
            const std::optional<ValidationResultElement> getFirstError() const;

            void trigger() const;

            operator bool() const;
            bool operator==(const ValidationResult& other) const;

            void writeValidationResults(std::ostream& stream) const;
            std::string getValidationReport() const;

            friend std::ostream& operator<<(std::ostream& os, const ValidationResult& validationResult);
    };
}

#include "validationresult.txx"

#endif // VALIDATIONRESULT_H
