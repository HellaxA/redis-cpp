#include "get.hpp"
#include "../constants.hpp"
#include "../resp_parser/resp_converter.hpp"
#include <cstddef>

inline int MIN_ARG_NUM = 5;
inline int GET_KEY_ID = 4;

// Format example: ["*2", "$4", "GET", "$3", "hey"]
std::string Get(std::vector<std::string>& input, Store& store) {
    std::string result {};

    size_t vec_len = input.size();

    if (vec_len < MIN_ARG_NUM) {
        return NULL_BULK_STRING;
    }
    std::string key = input.at(GET_KEY_ID);
    auto opt = store.Get(key);

    if (opt.has_value()) {
        return ConvertToBulkString(opt.value());
    }
    return NULL_BULK_STRING;
}
