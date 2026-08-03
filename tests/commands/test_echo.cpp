#include "../../src/commands/echo.hpp"
#include <gtest/gtest.h>
#include <vector>
#include <string>

TEST(echo, default_case) {
    std::vector<std::string> input = {"*2", "$4", "ECHO", "$3", "hey"};
    std::string actual = Echo(input);
    std::string expected = "$3\r\nhey\r\n";
    EXPECT_EQ(expected, actual);
}

TEST(echo, empty_input) {
    std::vector<std::string> input {};
    std::string actual = Echo(input);
    std::string expected = "";
    EXPECT_EQ(expected, actual);
}
