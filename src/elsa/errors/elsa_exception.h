#pragma once

#include <string>
#include <exception>

namespace elsa {
    namespace errors {

        class ElsaException : public std::exception
        {
        public:
            ElsaException(const std::string& message);

            virtual const char* what() const throw();

        protected:
            std::string message_;
        };

    }
}