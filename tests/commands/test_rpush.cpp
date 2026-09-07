#include "../../src/commands/get.hpp"
#include "../../src/commands/set.hpp"
#include "../../src/commands/rpush.hpp"
#include "../../src/store/store.hpp"
#include "../../src/constants.hpp"
#include <gtest/gtest.h>
#include <vector>
#include <string>

TEST(rpush, double_add_size_check) {
    Store store;

    std::vector<std::string> input_set = {"*3", "$5", "RPUSH", "$8", "list_key", "$12", "\"list_value1\""};
    auto res1 = Rpush(input_set, store);
    EXPECT_EQ(":1\r\n", res1);

    input_set = {"*3", "$5", "RPUSH", "$8", "list_key", "$12", "\"list_value2\""};
    auto res2 = Rpush(input_set, store);
    EXPECT_EQ(":2\r\n", res2);
}

TEST(rpush, double_add_vec_check) {
    Store store;

    std::vector<std::string> input_set = {"*3", "$5", "RPUSH", "$8", "list_key", "$12", "\"list_value1\""};
    Rpush(input_set, store);

    input_set = {"*3", "$5", "RPUSH", "$8", "list_key", "$12", "\"list_value2\""};
    Rpush(input_set, store);

    auto list = std::get<std::vector<std::string>>(store.Get("list_key").value());

    auto expected_list = std::vector<std::string>{"\"list_value1\"", "\"list_value2\""};

    EXPECT_EQ(expected_list, list);
}

TEST(rpush, non_list_key_already_exists) {
    Store store;

    std::vector<std::string> input_set = {"*3", "$3", "SET", "$8", "list_key", "$6", "value1"};
    Set(input_set, store);

    input_set = {"*3", "$5", "RPUSH", "$8", "list_key", "$12", "\"list_value2\""};
    auto actual = Rpush(input_set, store);

    EXPECT_EQ(":-1\r\n", actual);
}
