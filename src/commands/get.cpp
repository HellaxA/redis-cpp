#include "get.hpp"
#include "../constants.hpp"
#include "../resp_parser/resp_converter.hpp"
#include <cstddef>

std::string Get(std::vector<std::string>& input, Store& store) {
    std::string result {};

    size_t vec_len = input.size();

    // TODO return error
    if (vec_len < 4) {
        return NULL_BULK_STRING;
    }
    std::string key = input.at(4);
    auto opt = store.Get(key);

    if (opt.has_value()) {
        return ConvertToSimpleString(opt.value());
    }
    return NULL_BULK_STRING;
}
