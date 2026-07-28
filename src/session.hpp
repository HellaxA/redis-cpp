#pragma once
#include <asio.hpp>
#include <asio/awaitable.hpp>

asio::awaitable<void> session(asio::ip::tcp::socket socket);
