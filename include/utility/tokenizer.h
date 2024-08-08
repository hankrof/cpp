#ifndef __UTILITY_TOKENIZER_H__
#define __UTILITY_TOKENIZER_H__
#include <string>
#include <vector>
namespace utility
{
    class Tokenizer
    {
    public:
        virtual ~Tokenizer(){}
        virtual std::vector<std::string> split(const std::string text, const std::string delimeter);
    };
}
#endif
