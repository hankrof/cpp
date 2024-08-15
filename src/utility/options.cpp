#include "utility/options.h"
#include <stdexcept>
#include <string_view>
using namespace utility;
Options::Options(const std::vector<std::string> &options)
    : _options(options)
{

}

std::map<std::string, std::string> Options::parse(int argc, const char *const *argv) const
{
    auto tokens(convertArgsToTokens(argc, argv));
    throwIfAnyTokenIsInvalid(tokens);
    return parseTokensToTable(tokens);
}

std::vector<std::string_view> Options::convertArgsToTokens(int argc, const char* const *argv) const
{
    return std::vector<std::string_view>(argv + 1, argv + argc);
}

void Options::throwIfTokensAreNotPaired(const std::vector<std::string_view> &tokens) const
{
   if (tokens.size() % 2)
       throw std::invalid_argument(__PRETTY_FUNCTION__ + std::string( "tokens should be paired!"));
}

void Options::throwIfKeyIsInvalid(const std::string_view &key) const
{
    if (key.empty())
        throw std::invalid_argument(__PRETTY_FUNCTION__ + std::string(" key is empty"));

    if (key.size() < 3) // --something
        throw std::invalid_argument(__PRETTY_FUNCTION__ + std::string(" keys size() should be greater than 3"));

    if (key[0] != '-' && key[1] != '-')
        throw std::invalid_argument(__PRETTY_FUNCTION__ + std::string(" keys should be started by --"));
}

void Options::throwIfValueIsInvalid(const std::string_view &value) const
{
    if (value.empty())
        throw std::invalid_argument(__PRETTY_FUNCTION__ + std::string(" value is empty"));

    if (value.size() >= 2 && (value[0] == '-' || value[1] == '-'))
        throw std::invalid_argument(__PRETTY_FUNCTION__ + std::string(" value should not be started by -"));
}

void Options::throwIfAnyTokenIsInvalid(const std::vector<std::string_view> &tokens) const
{
    throwIfTokensAreNotPaired(tokens);
    for (decltype(tokens.size()) i = 0; i < tokens.size() / 2; i++)
    {
        throwIfKeyIsInvalid(tokens[i * 2]);
        throwIfValueIsInvalid(tokens[i * 2 + 1]);
    }
}

std::map<std::string, std::string> Options::parseTokensToTable(const std::vector<std::string_view> &tokens) const
{
    std::map<std::string , std::string> table;
    for (decltype(tokens.size()) i = 0; i < tokens.size() / 2; i++)
        table[std::string (tokens[i * 2].data() + 2, tokens[i * 2].size() - 2)]
          = std::string(tokens[(i * 2) + 1].data(), tokens[(i * 2) + 1].size());
    return table;
}

