#include <gtest/gtest.h>
#include <rfl.hpp>
#include <rfl/json.hpp>
#include <filesystem>
#include "domain/person.h"

TEST(ReflectCppTest, ReflectFromJsonString)
{
    const auto homer = domain::Person {"Homer", "Simpson", 45};
    const std::string jsonStr = rfl::json::write(homer);
    auto reflHomer = rfl::json::read<domain::Person>(jsonStr).value();
    ASSERT_EQ(homer, reflHomer);
}

TEST(ReflectCppTest, ReflectFromJsonFile)
{
    const std::string str = "{\"firstName\":\"Homer\",\"lastName\":\"Simpson\",\"age\":45}";
    const std::string filename = "homer.json";

    std::ofstream outputFile(filename);
    outputFile << str;
    outputFile.close();

    std::ifstream inputFile(filename);
    auto homer = rfl::json::read<domain::Person>(inputFile).value();
    ASSERT_EQ(rfl::json::write(homer), str);

    std::filesystem::remove(filename);
}
