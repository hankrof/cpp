#ifndef __OPTIONS_H__
#define __OPTIONS_H__
#include <string>
#include <vector>
#include <map>
namespace utility
{
    class Options
    {
    public:
        explicit Options(const std::vector<std::string> &options);
        std::map<std::string, std::string> parse(int argc, const char *const *argv) const;
    private:
        std::vector<std::string_view> convertArgsToTokens(int argc, const char* const *argv) const;
        void throwIfTokensAreNotPaired(const std::vector<std::string_view>& tokens) const;
        void throwIfKeyIsInvalid(const std::string_view& key) const;
        void throwIfValueIsInvalid(const std::string_view& value) const;
        void throwIfAnyTokenIsInvalid(const std::vector<std::string_view>& tokens) const;
        std::map<std::string, std::string> parseTokensToTable(const std::vector<std::string_view>& tokens) const;
        std::vector<std::string> _options;
    };
}
#endif
