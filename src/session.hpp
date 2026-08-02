#pragma once
#include <asio.hpp>
#include <asio/awaitable.hpp>

asio::awaitable<void> Session(asio::ip::tcp::socket socket);
