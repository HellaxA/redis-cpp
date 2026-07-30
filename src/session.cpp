#include "session.hpp"
#include <iostream>
#include <string>
#include <string_view>
#include "resp_parser/resp.hpp"

using asio::ip::tcp;

asio::awaitable<void> session(tcp::socket socket) {
	std::cout << std::unitbuf;
	std::cerr << std::unitbuf;
	try {
		char data[1024] = {};
		for (;;) 
		{
			std::size_t n = co_await socket.async_read_some(asio::buffer(data), asio::use_awaitable);
			std::string server_response;

			std::string_view received(data, n);
			if (received == "bulk\n")
			{
				server_response = convert_to_bulk_string("PONG");
			} else 
			{
				server_response = convert_to_simple_string("PONG");
			}

			co_await async_write(socket, asio::buffer(server_response, server_response.length()),
					asio::use_awaitable);
		}
	} catch (std::exception& e) {
        std::cerr << "Session error: " << e.what() << "\n";
    }
}
