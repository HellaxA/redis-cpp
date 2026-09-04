#include "get.hpp"
#include "../constants.hpp"
#include "../resp_parser/resp_converter.hpp"
#include <cstddef>
#include <variant>
#include <vector>

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

    if (!opt.has_value()) {
        return NULL_BULK_STRING;
    }

    auto val = opt.value();
    // rewrite with visitor
    if (std::holds_alternative<std::string>(val)) {
        return ConvertToBulkString(std::get<std::string>(val));
    } else if (std::holds_alternative<std::vector<std::string>>(val)) {
        return ConvertToArray(std::get<std::vector<std::string>>(val));
    }

    return NULL_BULK_STRING;
}
