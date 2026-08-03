#include <iostream>
#include <string>
#include <vector>
#include "../constants.hpp"

std::string Echo(std::vector<std::string>& input_vector) {
    std::string result {};

    size_t vec_len = input_vector.size();

    // TODO return error
    if (vec_len < 4) {
        return result;
    }

    for (size_t i = 3; i < input_vector.size() - 1; i += 2) {
        result.append(input_vector.at(i));
        result.append(CRLF);
        result.append(input_vector.at(i + 1));
        result.append(CRLF);
    }
    return result;
}
