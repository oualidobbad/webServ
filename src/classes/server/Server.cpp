#include "Server.hpp"

Server::Server() : _port(8080), _root("resources/sites/")
{
}

Server::~Server()
{
}

void Server::setPort(string port){
    char* end;
    errno = 0;
    long _port = strtol(port.c_str(), &end, 10);

    if (end == port.c_str() || *end != '\0')
        throw invalid_argument("Port is not a valid number: " + port);

    if (errno == ERANGE)
        throw out_of_range("Port number overflow: " + port);

    if (_port < 1 || _port > 65535)
        throw out_of_range("Port must be between 1 and 65535: " + port);
        
    this->_port = static_cast<int>(_port);
}

    // void validateRoot(const std::string& path) {
    //     // 1. Empty
    //     if (path.empty())
    //         throw std::invalid_argument("root path is empty");

    //     // 2. Must be absolute path
    //     if (path[0] != '/')
    //         throw std::invalid_argument("root must be an absolute path: " + path);

    //     // 3. Path exists + is a directory
    //     struct stat info;
    //     if (stat(path.c_str(), &info) != 0)
    //         throw std::invalid_argument("root path does not exist: " + path);

    //     if (!S_ISDIR(info.st_mode))
    //         throw std::invalid_argument("root path is not a directory: " + path);

    //     // 4. Readable
    //     if (access(path.c_str(), R_OK) != 0)
    //         throw std::runtime_error("root path is not readable: " + path);
    // }

void Server::setRoot(string root){
    this->_root = root;
}

const int& Server::getPort() const{
    return _port;
}
const string& Server::getRoot() const{
    return _root;
}