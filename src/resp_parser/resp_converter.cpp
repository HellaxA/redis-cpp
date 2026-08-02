#include <string>
#include "../constants.hpp"

std::string ConvertToSimpleString(std::string str) {
    return "+" + str + CRLF;
}

std::string ConvertToBulkString(std::string str) {
    return "$" + std::to_string(str.length()) + CRLF + str + CRLF;
}
