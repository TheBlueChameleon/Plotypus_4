#ifndef VALIDATIONRESULT_H
#define VALIDATIONRESULT_H

namespace Plotypus
{
    class ValidationResult
    {
        public:
            const static ValidationResult SUCCESS;

        private:
            std::optional<PlotypusError> error;

        public:
            ValidationResult() = default;

            template<ErrorType T>
            ValidationResult(const T& error);

            template<ErrorType T>
            static ValidationResult makeValidationResult(const std::optional<std::string> message = std::optional<std::string>());

            const PlotypusError& getError() const;
            void trigger() const;

            operator bool() const;
            bool operator==(const ValidationResult& other) const;
    };
}

#include "validationresult.txx"

#endif // VALIDATIONRESULT_H
