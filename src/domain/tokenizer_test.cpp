#include "domain/tokenizer.h"
#include <gtest/gtest.h>
TEST(Tokenizer, ParseABCD)
{
    domain::Tokenizer tokenizer;
    std::string input = "A B C D";
    std::string delim = " ";
    auto tokens = tokenizer.split(input, delim);

    ASSERT_EQ(tokens[0], "A");
    ASSERT_EQ(tokens[1], "B");
    ASSERT_EQ(tokens[2], "C");
    ASSERT_EQ(tokens[3], "D");
}

TEST(Tokenizer, Parse1920x1080)
{
    domain::Tokenizer tokenizer;
    std::string input = "1920 x 1080";
    std::string delim = " x";
    auto tokens = tokenizer.split(input, delim);

    ASSERT_EQ(tokens[0], "1920");
    ASSERT_EQ(tokens[1], "1080");
}

TEST(Tokenizer, SplitOneStringWithSpaceDelimeter)
{
    domain::Tokenizer tokenizer;
    std::string input = "hello";
    std::string delim = " ";
    auto tokens = tokenizer.split(input, delim);

    ASSERT_EQ(tokens.size(), 1);
    ASSERT_EQ(tokens[0], "hello");
}

TEST(Tokenizer, SplitOneStringWithoutDelimeter)
{
    domain::Tokenizer tokenizer;
    std::string input = "hello";
    std::string delim = "";
    auto tokens = tokenizer.split(input, delim);

    ASSERT_EQ(tokens.size(), 1);
    ASSERT_EQ(tokens[0], "hello");
}

TEST(Tokenizer, SplitOneStringHavingLeadingSpaceWithSpaceDelimeter)
{
    domain::Tokenizer tokenizer;
    std::string input = " hello";
    std::string delim = " ";
    auto tokens = tokenizer.split(input, delim);

    ASSERT_EQ(tokens.size(), 1);
    ASSERT_EQ(tokens[0],"hello");
}

TEST(Tokenizer, SplitOneStringHavingTrailingSpaceWithSpaceDelimeter)
{
    domain::Tokenizer tokenizer;
    std::string input = "hello ";
    std::string delim = " ";
    auto tokens = tokenizer.split(input, delim);

    ASSERT_EQ(tokens.size(), 1);
    ASSERT_EQ(tokens[0],"hello");
}
