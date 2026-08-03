#pragma once
#include <string>
#include <unordered_map>
#include <optional>

class Store {
public:
    void Set(const std::string& key, const std::string& value);
    std::optional<std::string> Get(const std::string& key);

private:
    std::unordered_map<std::string, std::string> data_;
};
