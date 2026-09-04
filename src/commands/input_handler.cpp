#include <cstddef>
#include <string>
#include <vector>
#include <iostream>
#include "input_handler.hpp"
#include "echo.hpp"
#include "set.hpp"
#include "get.hpp"
#include "rpush.hpp"
#include "../resp_parser/resp_parser.hpp"
#include "../resp_parser/resp_converter.hpp"
#include "../helpers/helpers.hpp"
#include "../store/store.hpp"
#include "../constants.hpp"

inline int MIN_ARG_NUM = 2;
std::string HandleCommand(std::string& input, Store& store) {
    char data_type = input[0];

    if (data_type == '*') {
        std::vector<std::string> input_vector = ParseArray(input);
        std::string command_name = ToLower(input_vector.at(2));

        if (command_name == "echo") {
            return Echo(input_vector);
        } else if (command_name == "set") {
            return Set(input_vector, store);
        } else if (command_name == "get") {
            return Get(input_vector, store);
        } else if (command_name == "ping") {
            return ConvertToSimpleString("PONG");
        } else if (command_name == "rpush") {
            return Rpush(input_vector, store);
        }
    }
    return "no command found";
}
