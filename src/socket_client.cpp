#include "headers/socket_client.hpp"

namespace lib
{
    namespace net
    {
        namespace sockets
        {
            socket_client::socket_client(
                string const& ip, 
                uint16_t port, 
                socket_type type, 
                bool is_open)
                : socket_base(type, is_open), _is_address_set(true)
            {
                socket_base::set_address(ip, port, _address);
            }

            socket_client::socket_client(socket_type type, bool is_open) 
                : socket_base(type, is_open), _is_address_set(false)
            {}

            void socket_client::connect_to(string const& ip, uint16_t port)
            {
                sockaddr_in address;
                socket_base::set_address(ip, port, address);

                if (::connect(_fd, (sockaddr *) &address, sizeof(sockaddr)) < 0) {
                    throw;
                }

                _is_connected = true;
            }

            void socket_client::connect()
            {
                if (!_is_address_set) {
                    throw;
                }

                if (::connect(_fd, (sockaddr *) &_address, sizeof(sockaddr)) < 0) {
                    throw;
                }

                _is_connected = true;
            }

            bool socket_client::is_connected() const noexcept
            {
                return _is_connected;
            }

            void socket_client::set_address(string const& ip, uint16_t port)
            {
                socket_base::set_address(ip, port, _address);

                _is_address_set = true;
            }

            void socket_client::unset_address()
            {
                if (!_is_address_set) {
                    throw;
                }

                _is_address_set = false;
            }
            
            bool socket_client::is_address_set() const noexcept
            {
                return _is_address_set;
            }
        }
    }
}