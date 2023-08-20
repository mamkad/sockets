#pragma once

#include "socket_base.hpp"

namespace lib
{
    namespace net
    {
        namespace sockets
        {
            class socket_client final : public socket_base
            {
                bool _is_address_set;
                
            public:
                socket_client(string const& ip, uint16_t port, socket_type type = socket_type::TCP, bool is_open = true);
                socket_client(socket_type type, bool is_open = true);

                void connect_to(string const& ip, uint16_t port);
                void connect();

                bool is_connected() const noexcept;

                void set_address(string const& ip, uint16_t port);
                void unset_address();

                bool is_address_set() const noexcept;
            };
        }
    }
}