#include "../../src/helpers/helpers.hpp"
#include <gtest/gtest.h>

TEST(Split, simple_space_string) {
    std::vector<std::string> actual = Split("foo bar gaz", " ");
    std::vector<std::string> expected {"foo", "bar", "gaz"};
    EXPECT_EQ(expected, actual);
}

TEST(Split, crlf_delimeter_string) {
    std::vector<std::string> actual = Split(" foo\r\nbar\r\ngaz\r\n", "\r\n");
    std::vector<std::string> expected {" foo", "bar", "gaz"};
    EXPECT_EQ(expected, actual);
}

TEST(Split, array_bulk_string) {
    std::vector<std::string> actual = Split("*2\r\n$4\r\nECHO\r\n$3\r\nhey\r\n", "\r\n");
    std::vector<std::string> expected {"*2", "$4", "ECHO", "$3", "hey"};
    EXPECT_EQ(expected, actual);
}

TEST(Split, empty_string) {
    std::vector<std::string> actual = Split("", "\r\n");
    std::vector<std::string> expected {};
    EXPECT_EQ(expected, actual);
}

// might fix in the future
TEST(Split, empty_delimeter) {
    std::vector<std::string> actual = Split("foo bar", "");
    std::vector<std::string> expected {};
    EXPECT_EQ(expected, actual);
}


TEST(ToLower, simle_string) {
    std::string actual = ToLower("FOOGAZ");
    std::string expected = "foogaz";
    EXPECT_EQ(expected, actual);
}

TEST(ToLower, empty_string) {
    std::string actual = ToLower("");
    std::string expected = "";
    EXPECT_EQ(expected, actual);
}
