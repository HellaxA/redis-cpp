#include "set.hpp"
#include "../constants.hpp"

inline int MIN_ARG_NUM = 7;
inline int SET_KEY_ID = 4;
inline int SET_KEY_VALUE = 6;

// Format example: ["*2", "$4", "SET", "$3", "hey", "$3", "bar"]
std::string Set(std::vector<std::string>& input, Store& store) {
    std::string result {};

    size_t vec_len = input.size();

    if (vec_len < MIN_ARG_NUM) {
        return NULL_BULK_STRING;
    }

    store.Set(input.at(SET_KEY_ID), input.at(SET_KEY_VALUE));

    return OK_SIMPLE_STRING;
}
