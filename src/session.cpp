#include "session.hpp"
#include <iostream>

using asio::ip::tcp;

asio::awaitable<void> session(tcp::socket socket) {
	std::cout << std::unitbuf;
	std::cerr << std::unitbuf;
	try {
		char data[1024];
		for (;;) 
		{
			std::size_t n = co_await socket.async_read_some(asio::buffer(data), asio::use_awaitable);

			const char* server_response = "+PONG\r\n";

            co_await async_write(socket,
                asio::buffer(server_response, strlen(server_response)), asio::use_awaitable);
		}
	} catch (std::exception& e) {
        std::cerr << "Session error: " << e.what() << "\n";
    }
}
