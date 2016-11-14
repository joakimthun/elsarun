#include "elsa_exception.h"

namespace elsa {
    namespace errors {

        ElsaException::ElsaException(const std::string& message) : message_(message) {};

        const char* ElsaException::what() const throw()
        {
            return message_.c_str();
        }
    }
}
