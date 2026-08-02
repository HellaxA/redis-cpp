#include "../../src/helpers/helpers.hpp"
#include <gtest/gtest.h>

TEST(split, simple_space_string) {
    std::vector<std::string> actual = split("foo bar gaz", " ");
    std::vector<std::string> expected {"foo", "bar", "gaz"};
    EXPECT_EQ(expected, actual);
}

TEST(split, crlf_delimeter_string) {
    std::vector<std::string> actual = split(" foo\r\nbar\r\ngaz\r\n", "\r\n");
    std::vector<std::string> expected {" foo", "bar", "gaz"};
    EXPECT_EQ(expected, actual);
}

TEST(split, array_bulk_string) {
    std::vector<std::string> actual = split("*2\r\n$4\r\nECHO\r\n$3\r\nhey\r\n", "\r\n");
    std::vector<std::string> expected {"*2", "$4", "ECHO", "$3", "hey"};
    EXPECT_EQ(expected, actual);
}

TEST(split, empty_string) {
    std::vector<std::string> actual = split("", "\r\n");
    std::vector<std::string> expected {};
    EXPECT_EQ(expected, actual);
}

// might fix in the future
TEST(split, empty_delimeter) {
    std::vector<std::string> actual = split("foo bar", "");
    std::vector<std::string> expected {};
    EXPECT_EQ(expected, actual);
}
