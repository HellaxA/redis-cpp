#include "../../src/commands/get.hpp"
#include "../../src/commands/set.hpp"
#include "../../src/store/store.hpp"
#include "../../src/constants.hpp"
#include <gtest/gtest.h>
#include <vector>
#include <string>

TEST(set, returns_ok) {
    std::vector<std::string> input = {"*2", "$4", "SET", "$3", "hey", "$3", "bar"};
    Store store;
    auto actual = Set(input, store);

    EXPECT_EQ(OK_SIMPLE_STRING, actual);
}

TEST(get, returns_null) {
    std::vector<std::string> input = {"*2", "$4", "GET", "$3", "hey"};
    Store store;
    auto actual = Get(input, store);

    EXPECT_EQ(NULL_BULK_STRING, actual);
}

TEST(set_get, sanity_check) {
    std::vector<std::string> input_set = {"*2", "$4", "SET", "$3", "hey", "$3", "bar"};
    Store store;
    Set(input_set, store);

    std::vector<std::string> input_get = {"*2", "$4", "GET", "$3", "hey"};
    auto actual = Get(input_get, store);
 
    EXPECT_EQ("$3\r\nbar\r\n", actual);
}
