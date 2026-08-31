#include "set.hpp"
#include "../constants.hpp"
#include "../helpers/helpers.hpp"
#include <chrono>
#include <iostream>

inline int MIN_ARG_NUM = 7;
inline int MIN_TTL_ARG_NUM = 10;
inline int SET_KEY_ID = 4;
inline int SET_KEY_VALUE = 6;
inline int PX_ARG_ORDER = 8;
inline int PX_VALUE_ORDER = 9;

// Format example: ["*2", "$4", "SET", "$3", "hey", "$3", "bar"]
// Format example with TTL: ["*2", "$4", "SET", "$3", "hey", "$3", "bar", "$2", "PX", ":100"]
std::string Set(std::vector<std::string>& input, Store& store) {
    std::string result {};

    size_t vec_len = input.size();

    if (vec_len < MIN_ARG_NUM) {
        return NULL_BULK_STRING;
    }

    std::optional<std::chrono::milliseconds> ttl = std::nullopt;

    if (vec_len >= MIN_TTL_ARG_NUM &&
            ToLower(input.at(PX_ARG_ORDER)) == "px") {

        std::string ttl_value = input.at(PX_VALUE_ORDER);
        // add error handling for non numbers
        int value = std::stoi(ttl_value.substr(1, ttl_value.size() - 1));
        ttl = std::chrono::milliseconds(value);
    }

    store.Set(input.at(SET_KEY_ID), input.at(SET_KEY_VALUE), ttl);

    return OK_SIMPLE_STRING;
}
