#include <vector>
#include <string>

std::vector<std::string> split(const std::string& str, const std::string& delimeter) 
{
    std::vector<std::string> result;

    size_t start = 0;
    size_t end = str.find(delimeter);

    while (end != std::string::npos) 
    {
        std::string element = str.substr(start, end - start);
        result.push_back(element);
        start = end + delimeter.length();
        end = str.find(delimeter);
    }

    result.push_back(str.substr(start));
    return result;
}
