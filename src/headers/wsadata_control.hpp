#pragma once

#include <winsock.h>

namespace lib
{
    namespace net
    {
        namespace sockets
        {
            class wsadata_control 
            {
                WSADATA _wsadata;

            protected:
                wsadata_control();
                ~wsadata_control();
            };
        }
    }
}