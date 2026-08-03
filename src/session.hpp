#pragma once
#include <asio.hpp>
#include <asio/awaitable.hpp>
#include "store/store.hpp"

asio::awaitable<void> Session(asio::ip::tcp::socket socket, Store& store);
