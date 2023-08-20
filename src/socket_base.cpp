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
                _is_connected = false;

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

                _fd = INVALID_SOCKET;
                _is_connected = false;

                close_socket();
            }

            void socket_base::shutdown()
            {
                if (!is_open()) {
                    throw;
                }

                _fd = INVALID_SOCKET;
                _is_connected = false;
                
                if (::shutdown(_fd, 2) < 0) {
                    throw;
                }
            }

            bool socket_base::is_open() const noexcept
            {
                return _fd != INVALID_SOCKET;
            }
 
            socket_type socket_base::get_type() const noexcept
            {
                return _type;
            }

            int socket_base::send(vector<char> const& buff)
            {
                if (buff.size() == 0) {
                    throw;
                }

                int send_bytes = ::send(_fd, buff.data(), buff.size(), 0);

                if (send_bytes < buff.size()) {
                    throw;
                }

                return send_bytes;
            }

            int socket_base::recv(vector<char>& buff)
            {
                if (buff.size() == 0) {
                    throw;
                }

                int recv_bytes = ::recv(_fd, buff.data(), buff.size(), 0);

                if (recv_bytes < buff.size()) {
                    throw;
                }

                return recv_bytes;
            }

            void socket_base::create_socket()
            {
                _fd = socket(AF_INET, get_code_by_type(_type), 0);

                if (_fd < 0) {
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
                if (::closesocket(_fd) < 0) {
                    throw;
                }
            }

            void socket_base::set_address(string const& ip, uint16_t port, sockaddr_in& address)
            {
                address.sin_family = AF_INET;
                address.sin_port = htons(port);
                address.sin_addr.s_addr = inet_addr(ip.data());
            }
        }
    }
}