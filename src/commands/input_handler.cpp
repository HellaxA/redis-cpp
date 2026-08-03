#include <cstddef>
#include <string>
#include <vector>
#include <iostream>
#include "input_handler.hpp"
#include "echo.hpp"
#include "set.hpp"
#include "get.hpp"
#include "../resp_parser/resp_parser.hpp"
#include "../resp_parser/resp_converter.hpp"
#include "../helpers/helpers.hpp"
#include "../store/store.hpp"
#include "../constants.hpp"

std::string HandleCommand(std::string& input, Store& store) {
    char data_type = input[0];

    if (data_type == '*') {
        std::vector<std::string> input_vector = ParseArray(input);
        // TODO return error
        if (input_vector.size() < 2) {
            return NULL_BULK_STRING;
        }

        if (ToLower(input_vector.at(2)) == "echo") {
            return Echo(input_vector);
        } else if (ToLower(input_vector.at(2)) == "set") {
            return Set(input_vector, store);
        } else if (ToLower(input_vector.at(2)) == "get") {
            return Get(input_vector, store);
        }

    }

    return ConvertToSimpleString("PONG");
}
