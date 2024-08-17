#ifndef CALAGEN_H
#define CALAGEN_H 60

#include <cstdlib>

#if defined(__linux__)

#include <system_error>
#include <libssh/libssh.h>
#include <iostream>
#include <stdexcept>

namespace calagen
{
    /*
    @brief calagen error hendler
    */
    void calagen_error(const std::exception& e, const std::string& additional_info = "") {
    std::cerr << "Error: " << e.what() << std::endl;
    if (!additional_info.empty()) {
        std::cerr << "Additional info: " << additional_info << std::endl;
    }

    class calagen{
        
    };
}
} // namespace calagen

#endif

#endif // !1



