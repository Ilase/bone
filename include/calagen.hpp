#ifndef CALAGEN_H
#define CALAGEN_H 60

#include <cstdlib>

#if defined(__linux__)


#include <system_error>
#include <libssh/libssh.h>
#include <iostream>
#include <stdexcept>
#include <libssh/libssh.h>
#include <string>

namespace bone
{
    /*
    @brief calagen error hendler
    */
    void calagen_error(const std::exception& e, const std::string& additional_info = "") {
    std::cerr << "Error: " << e.what() << std::endl;
    if (!additional_info.empty()) {
        std::cerr << "Additional info: " << additional_info << std::endl;
        }
    }
    class calagen {
        std::string name;
        ssh_session session;
        std::string address;
        int verbocity;
        int port;

        public:
        calagen(std::string name, std::string adress, int port);
        ~calagen();
        inline bool is_active();
        void open();
        void close();
        std::string get_adress();
    };
} // namespace calagen

#endif

#endif // !1



