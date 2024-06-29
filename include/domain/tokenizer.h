#ifndef __TOKENIZER_H__
#define __TOKENIZER_H__
#include <string>
#include <vector>
namespace domain
{
    class Tokenizer
    {
    public:
        virtual ~Tokenizer(){}
        virtual std::vector<std::string> split(const std::string text, const std::string delimeter);
    };
}
#endif
