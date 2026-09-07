#include "store.hpp"
#include <chrono>
#include <optional>
#include <string>
#include <unordered_map>
#include <iostream>
#include <variant>
#include <vector>

void Store::Set(const std::string& key, const ActualValue& value,
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

    data_[key] = MapValue{value, expiry};
}

std::optional<ActualValue> Store::Get(const std::string& key) {
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

std::optional<size_t> Store::Rpush(const std::string& key, const std::string& value) {
    auto list_it = data_.find(key);

    if (list_it == data_.end()) {
        data_[key] = MapValue{std::vector<std::string>{value}, std::nullopt};
        return 1;
    }

    // add expiration for lists
    // if (list_it->second.expiry.has_value() && std::chrono::steady_clock::now() > list_it->second.expiry.value()) {
    //     data_.erase(list_it);
    //     return std::nullopt;
    // }

    if (!std::holds_alternative<std::vector<std::string>>(list_it->second.value)) {
        return std::nullopt;
    }

    auto& list = std::get<std::vector<std::string>>(list_it->second.value);
    list.push_back(value);

    return list.size();
}
















