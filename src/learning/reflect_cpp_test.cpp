#include <gtest/gtest.h>
#include <rfl.hpp>
#include <rfl/json.hpp>
TEST(ReflectCppTest, HelloWorld)
{
    struct Person {
        std::string first_name;
        std::string last_name;
        int age;
    };

    const auto homer =
        Person{.first_name = "Homer",
               .last_name = "Simpson",
               .age = 45};

    const std::string json_string = rfl::json::write(homer);
    auto homer2 = rfl::json::read<Person>(json_string).value();
}
