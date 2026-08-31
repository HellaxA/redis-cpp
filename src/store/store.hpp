#pragma once
#include <chrono>
#include <string>
#include <unordered_map>
#include <optional>

struct ValueEntry {
    std::string value;
    std::optional<std::chrono::steady_clock::time_point> expiry;
};

class Store {
    public:
        void Set(const std::string& key, const std::string& value,
                std::optional<std::chrono::milliseconds> ttl = std::nullopt);
        std::optional<std::string> Get(const std::string& key);

    private:
        std::unordered_map<std::string, ValueEntry> data_;
};
