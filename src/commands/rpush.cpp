#include "input_handler.hpp"
#include "../constants.hpp"
#include "../helpers/helpers.hpp"
#include "../resp_parser/resp_converter.hpp"

inline int MIN_ARG_NUM = 7;

// 
std::string Rpush(std::vector<std::string>& input, Store& store) {
    std::string result{};

    size_t vec_len = input.size();

    if (vec_len < MIN_ARG_NUM) {
        return NULL_BULK_STRING;
    }

    return ConvertToInteger(1);
}
