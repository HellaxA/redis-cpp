#include <string>
#include "../constants.hpp"

std::string convert_to_simple_string(std::string str) {
    return "+" + str + CRLF;
}

std::string convert_to_bulk_string(std::string str) {
    return "$" + std::to_string(str.length()) + CRLF + str + CRLF;
}
