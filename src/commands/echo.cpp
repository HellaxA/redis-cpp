#include <iostream>
#include <string>
#include <vector>
#include "../constants.hpp"

inline int MIN_ARG_NUM = 5;
inline int ECHOED_STR_LEN_ID = 3;
inline int ECHOED_STR = 4;

// Array format example: ["*2", "$4", "ECHO", "$3", "hey"]
std::string Echo(std::vector<std::string>& input_vector) {
    std::string result {};

    size_t vec_len = input_vector.size();

    // TODO return error
    if (vec_len < MIN_ARG_NUM) {
        return result;
    }

    result.append(input_vector.at(ECHOED_STR_LEN_ID));
    result.append(CRLF);
    result.append(input_vector.at(ECHOED_STR));
    result.append(CRLF);
    return result;
}
