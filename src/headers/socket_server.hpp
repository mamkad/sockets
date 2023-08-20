#pragma once

#include "socket_base.hpp"
#include "socket_client.hpp"

namespace lib
{
    namespace net
    {
        namespace sockets
        {
            class socket_server final : public socket_base
            {
            public:
                socket_server(string const& ip, uint16_t port, socket_type type, bool is_open = true);
                socket_server(socket_type type, bool is_open = true);

                void bind();
                void listen(int backlog);
                socket_client accept();
            };
        }
    }
}