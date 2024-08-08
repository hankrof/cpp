#include <gtest/gtest.h>
#include <rfl.hpp>
#include <rfl/json.hpp>
#include "domain/person.h"

TEST(ReflectCppTest, ReflectFromJsonString)
{
    const auto homer = domain::Person {"Homer", "Simpson", 45};
    const std::string json_string = rfl::json::write(homer);
    auto reflHomer = rfl::json::read<domain::Person>(json_string).value();
    ASSERT_EQ(homer, reflHomer);
}
