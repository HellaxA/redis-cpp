#include "server.hpp"
#include "session.hpp"
#include <asio/awaitable.hpp>
#include <asio/co_spawn.hpp>
#include <asio/io_context.hpp>
#include <iostream>

using asio::ip::tcp;

asio::awaitable<void> Listener(asio::io_context& io_context, unsigned short port) {
    tcp::acceptor acceptor(io_context, {tcp::v4(), port});
    std::cout << "Waiting for a client to connect...\n";
    std::cout << "Logs from your program will appear here!\n";
    for (;;) {
        tcp::socket socket = co_await acceptor.async_accept(asio::use_awaitable);
        std::cout << "Client connected\n";
        asio::co_spawn(io_context, Session(std::move(socket)), asio::detached);
    }
}
