#include <string>
#include <vector>
#include <iostream>
#include "input_handler.hpp"
#include "echo.hpp"
#include "../resp_parser/resp_parser.hpp"
#include "../resp_parser/resp_converter.hpp"
#include "../helpers/helpers.hpp"

std::string HandleCommand(std::string& input) {
    char data_type = input[0];

    if (data_type == '*') {
        std::vector<std::string> input_vector = ParseArray(input);

        if (ToLower(input_vector.at(2)) == "echo") {
            return Echo(input_vector);
        }

    }

    return ConvertToSimpleString("PONG");
}
