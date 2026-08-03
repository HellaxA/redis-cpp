#include "set.hpp"
#include "../constants.hpp"

std::string Set(std::vector<std::string>& input, Store& store) {
    std::string result {};

    size_t vec_len = input.size();

    // TODO return error
    if (vec_len < 6) {
        return NULL_BULK_STRING;
    }

    store.Set(input.at(4), input.at(6));

    return OK_SIMPLE_STRING;
}
