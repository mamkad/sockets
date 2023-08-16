#include "headers/wsadata_control.hpp"

namespace lib
{
    namespace net
    {
        namespace sockets
        {
            wsadata_control::wsadata_control()
            {
                if (WSAStartup(MAKEWORD(2,0), &_wsadata)) {
                    throw;
                }
            }

            wsadata_control::~wsadata_control()
            {
                WSACleanup();
            }
        }
    }
}