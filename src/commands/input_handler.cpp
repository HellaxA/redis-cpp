#include <string>
#include <vector>
#include "input_handler.hpp"
#include "../resp_parser/resp_parser.hpp"

// TODO reference instead of copying
std::string handle_command(std::string input) {
    char data_type = input[0];

    if (data_type == '*') {
        std::vector<std::string> result;
    }

    return "";
}
