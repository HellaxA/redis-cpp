#include <vector>
#include <iostream>
#include <string>

// could optimize by using string view of the provided string, instead of creating new string for every substring.
std::vector<std::string> Split(const std::string& str, const std::string& delimeter) {
    std::vector<std::string> result;
    if (str.empty() || delimeter.empty()) {
        return result;
    }

    size_t start = 0;
    size_t end = str.find(delimeter);
    size_t del_length = delimeter.length();

    while (end != std::string::npos) {

        std::string element = str.substr(start, end - start);

        result.push_back(element);

        end += del_length;
        start = end;
        end = str.find(delimeter, end);
    }

    // to omit adding extra empty string "" in the vector
    if (start < str.length()) {
        result.push_back(str.substr(start));
    }

    return result;
}

std::string ToLower(std::string s) {
    std::transform(s.begin(), s.end(), s.begin(),
                   [](unsigned char c) { return std::tolower(c); });
    return s;
}
