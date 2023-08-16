#pragma once

#include "../enums/socket_type.hpp"
#include "wsadata_control.hpp"

namespace lib
{
    namespace net
    {
        namespace sockets
        {
            class socket_base : public wsadata_control
            {
                SOCKET _fd;
                socket_type _type;

            protected:
                socket_base(socket_type type, bool is_open = true);
                ~socket_base();

            public:
                void open();
                void close();

                bool is_open() const noexcept;

                socket_type get_type() const noexcept;

            private:
                void create_socket();
                static int get_code_by_type(socket_type type);
                void close_socket();
            };
        }
    }
}