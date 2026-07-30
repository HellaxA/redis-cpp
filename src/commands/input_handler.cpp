#include <string>
#include "input_handler.hpp"
#include "../resp_parser/resp_parser.hpp"

std::string handle_command(std::string input) {
    char data_type = input[0];

    std::string command_response;
    if (data_type == '*') {
        command_response = parse_array(input);
    }
    return command_response;
}
