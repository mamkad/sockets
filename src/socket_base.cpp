#include "headers/socket_base.hpp"

namespace lib
{
    namespace net
    {
        namespace sockets
        {
            socket_base::socket_base(socket_type type, bool is_open)
            {
                _fd = INVALID_SOCKET;
                _type = type;

                if (is_open) {
                    create_socket();
                }
            }

            socket_base::~socket_base()
            {
                if (is_open()) {
                    close_socket();
                }
            }

            void socket_base::open()
            {
                if (is_open()) {
                    throw;
                }
                create_socket();
            }

            void socket_base::close()
            {
                if (!is_open()) {
                    throw;
                }
                close_socket();
            }

            bool socket_base::is_open() const noexcept
            {
                return _fd != INVALID_SOCKET;
            }
 
            socket_type socket_base::get_type() const noexcept
            {
                return _type;
            }

            void socket_base::create_socket()
            {
                _fd = socket(AF_INET, get_code_by_type(_type), 0);
                if (_fd == INVALID_SOCKET) {
                    throw;
                }  
            }

            int socket_base::get_code_by_type(socket_type type)
            {
                int type_code = -1;
                switch (type) {
                    case TCP: {
                        type_code = SOCK_STREAM;
                        break;
                    }
                    default: {
                        throw;
                    }
                }
                return type_code;
            }

            void socket_base::close_socket()
            {
                closesocket(_fd);
            }
        }
    }
}