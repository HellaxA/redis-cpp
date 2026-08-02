#include "resp_parser.hpp"
#include <string>
#include <vector>
#include "../helpers/helpers.hpp"
#include "../constants.hpp"

std::vector<std::string> ParseArray(std::string& str) {
    std::vector<std::string> input_arguments = Split(str, CRLF);
    return input_arguments;
}

std::vector<std::string> ParseBulkString(std::string& str) {
    return std::vector<std::string> {};
}
