//#include "calagen.hpp"
#include "calagen.hpp"

bone::calagen::calagen(std::string name, std::string adress, int port){
    this->name = name;
    this->address = adress;
    this->port = port;
    this->verbocity = SSH_LOG_PROTOCOL;
    
    try{
        this->session = ssh_new();
    }
    catch(const std::exception& e){
        calagen_error(e, "Session init error");
    }
    
    ssh_options_set(this->session, SSH_OPTIONS_HOST, static_cast<void*>(&this->address));
    ssh_options_set(this->session, SSH_OPTIONS_LOG_VERBOSITY, &verbocity);
    ssh_options_set(this->session, SSH_OPTIONS_PORT, &port);
}

inline bool bone::calagen::is_active(){
    if(this->session == NULL) return false;
    return true;
}


void bone::calagen::close() {
    this->session;
}

std::string bone::calagen::get_adress(){
    return this->address;
}
