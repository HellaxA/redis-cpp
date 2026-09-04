#pragma once
#include <chrono>
#include <string>
#include <unordered_map>
#include <optional>
#include <variant>

using RedisValue = std::variant<std::string, std::vector<std::string>>;

struct ValueEntry {
    RedisValue value;
    std::optional<std::chrono::steady_clock::time_point> expiry;
};

class Store {
    public:
        void Set(const std::string& key, const RedisValue& value,
                std::optional<std::chrono::milliseconds> ttl = std::nullopt);
        std::optional<RedisValue> Get(const std::string& key);

    private:
        std::unordered_map<std::string, ValueEntry> data_;
};
