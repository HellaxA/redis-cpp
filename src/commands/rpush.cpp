#include "input_handler.hpp"
#include "../constants.hpp"
#include "../helpers/helpers.hpp"
#include "../resp_parser/resp_converter.hpp"

inline int MIN_ARG_NUM = 7;
inline int LIST_KEY_ORDER = 4;
inline int LIST_VALUE_ORDER = 6;

// Format example: ["*2", "$5", "RPUSH", "$8", "list_key", "$12", "\"list_value\""]
std::string Rpush(std::vector<std::string>& input, Store& store) {
    int result;

    size_t vec_len = input.size();

    if (vec_len < MIN_ARG_NUM) {
        return NULL_BULK_STRING;
    }

    auto key = input.at(LIST_KEY_ORDER);
    auto value = input.at(LIST_VALUE_ORDER);

    auto list_size_opt = store.Rpush(key, value);

    if (list_size_opt.has_value()) {
        return ConvertToInteger(list_size_opt.value());
    }

    return ConvertToInteger(-1);
}
