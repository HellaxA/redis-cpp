#include "store.hpp"
#include <chrono>
#include <optional>
#include <string>
#include <unordered_map>
#include <iostream>

void Store::Set(const std::string& key, const std::string& value,
        std::optional<std::chrono::milliseconds> ttl) { 

    std::optional<std::chrono::steady_clock::time_point> expiry = std::nullopt;
    if (ttl.has_value()) {
        expiry = std::chrono::steady_clock::now() + ttl.value();
    }

    // if (expiry.has_value()) {
    //
    //     auto ms = std::chrono::duration_cast<std::chrono::milliseconds>
    //         (expiry.value().time_since_epoch()).count();
    //     std::cout << ms << "<-expiry";
    //
    //     auto ttl_out = ttl.value().count();
    //     std::cout << ttl_out << "<-ttl";
    // }

    data_[key] = ValueEntry{value, expiry};
}

std::optional<std::string> Store::Get(const std::string& key) {
    auto pair = data_.find(key);

    if (pair == data_.end()) {
        return std::nullopt;
    }

    // if (pair->second.expiry.has_value()) {
    //
    //     auto ms = std::chrono::duration_cast<std::chrono::milliseconds>
    //         (pair->second.expiry.value().time_since_epoch()).count();
    //     std::cout << ms << "<-expiry";
    //
    //     auto now_out = std::chrono::duration_cast<std::chrono::milliseconds>
    //         (std::chrono::steady_clock::now().time_since_epoch()).count();
    //     std::cout << now_out << "<-now";
    // }

    if (pair->second.expiry.has_value() &&
            std::chrono::steady_clock::now() > pair->second.expiry.value()) {
        data_.erase(pair);
        return std::nullopt;
    }

    return pair->second.value;
}

