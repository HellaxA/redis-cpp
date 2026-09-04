#include "../../src/resp_parser/resp_converter.hpp"
#include <gtest/gtest.h>

TEST(resp_converter, convert_simple_string) {
    std::string actual = ConvertToSimpleString("gaz");
    std::string expected = "+gaz\r\n";
    EXPECT_EQ(expected, actual);
}

TEST(resp_converter, convert_bulk_string) {
    std::string actual = ConvertToBulkString("gaz");
    std::string expected = "$3\r\ngaz\r\n";
    EXPECT_EQ(expected, actual);
}

TEST(resp_converter, convert_integer) {
    std::string actual = ConvertToInteger(100);
    std::string expected = ":100\r\n";
    EXPECT_EQ(expected, actual);
}

TEST(resp_converter, convert_array_full) {
    std::vector<std::string> vec{"one", "two", "three"};
    std::string actual = ConvertToArray(vec);
    std::string expected = "*3\r\n$3\r\none\r\n$3\r\ntwo\r\n$5\r\nthree\r\n";
    EXPECT_EQ(expected, actual);
}

TEST(resp_converter, convert_array_empty) {
    std::vector<std::string> vec{};
    std::string actual = ConvertToArray(vec);
    std::string expected = "*0\r\n";
    EXPECT_EQ(expected, actual);
}
