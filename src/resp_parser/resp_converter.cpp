#include <string>
#include <vector>
#include "../constants.hpp"
#include <format>
#include "resp_converter.hpp"

std::string ConvertToSimpleString(const std::string& str) {
    return std::format("+{}{}", str, CRLF);
}

std::string ConvertToBulkString(const std::string& str) {
    return std::format("${}{}{}{}", str.length(), CRLF, str, CRLF);
}

std::string ConvertToInteger(const int num) {
    return std::format(":{}{}", num, CRLF);
}

std::string ConvertToArray(const std::vector<std::string>& list) {
    std::string result = "*" + std::to_string(list.size()) + CRLF;
    for (auto el : list) {
        result += "$" + std::to_string(el.size()) + CRLF + el + CRLF;
    }
    return result;
}
