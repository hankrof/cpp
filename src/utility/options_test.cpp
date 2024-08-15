#include "utility/options.h"
#include <gtest/gtest.h>
TEST(OptionTest, ParseOneNumber)
{
    utility::Options options ({
        "num",
    });

    const char* const argv[] {
        ".",
        "--num",
        "1",
    };

    constexpr int argc = sizeof(argv) / sizeof(argv[0]);

    auto items = options.parse(argc, argv);
    ASSERT_EQ(items["num"], "1");
}

TEST(OptionTest, ParseOneString)
{
    utility::Options options ({
        "str",
    });

    const char* const argv[] {
        ".",
        "--str",
        "helloworld",
    };

    constexpr int argc = sizeof(argv) / sizeof(argv[0]);

    auto items = options.parse(argc, argv);
    ASSERT_EQ(items["str"], "helloworld");
}

TEST(OptionTest, ParseOneNumberAndOneString)
{
    utility::Options options ({
        "num",
        "str",
    });

    const char* const argv[] {
        ".",
        "--num",
        "1",
        "--str",
        "helloworld",
    };

    constexpr int argc = sizeof(argv) / sizeof(argv[0]);

    auto items = options.parse(argc, argv);
    ASSERT_EQ(items["num"], "1");
    ASSERT_EQ(items["str"], "helloworld");
}
