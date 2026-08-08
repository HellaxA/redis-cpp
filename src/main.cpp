#include "server.hpp"
#include <asio/io_context.hpp>
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char **argv) {
  // Flush after every std::cout / std::cerr
  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;
  try {
      asio::io_context io_context;
      co_spawn(io_context, Listener(io_context, 6379), asio::detached);
      io_context.run();
  } catch(std::exception& e) {
      std::cerr << "Exception: " << e.what() << "\n";
  }
  return 0;
}
