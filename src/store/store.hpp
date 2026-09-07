#pragma once
#include <chrono>
#include <string>
#include <unordered_map>
#include <optional>
#include <variant>

using ActualValue = std::variant<std::string, std::vector<std::string>>;

struct MapValue {
    ActualValue value;
    std::optional<std::chrono::steady_clock::time_point> expiry;
};

class Store {
    public:
        void Set(const std::string& key, const ActualValue& value,
                std::optional<std::chrono::milliseconds> ttl = std::nullopt);
        std::optional<ActualValue> Get(const std::string& key);
        std::optional<size_t> Rpush(const std::string& key, const std::string& value);

    private:
        std::unordered_map<std::string, MapValue> data_;
};
