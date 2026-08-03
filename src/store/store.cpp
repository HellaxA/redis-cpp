#include "store.hpp"
#include <optional>
#include <string>
#include <unordered_map>

void Store::Set(const std::string& key, const std::string& value) {
    data_[key] = value;
}

std::optional<std::string> Store::Get(const std::string& key) {
    auto pair = data_.find(key);

    if (pair == data_.end()) {
        return std::nullopt;
    }
    return pair->second;
}

