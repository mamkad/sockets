#pragma once

#include "../enums/socket_type.hpp"
#include "wsadata_control.hpp"

#include <string>
#include <vector>
using std::string;
using std::vector;

namespace lib
{
    namespace net
    {
        namespace sockets
        {
            class socket_base : public wsadata_control
            {
            protected:
                SOCKET _fd;
                sockaddr_in _address;
                socket_type _type;
                bool _is_connected;

                socket_base(socket_type type, bool is_open);
                ~socket_base();

                void set_address(string const& ip, uint16_t port, sockaddr_in& address);

            public:
                void open();
                void close();
                void shutdown();

                bool is_open() const noexcept;

                socket_type get_type() const noexcept;

                int send(vector<char> const& buff);
                int recv(vector<char>& buff);

            private:
                void create_socket();
                void close_socket();

                static int get_code_by_type(socket_type type);
            };
        }
    }
}