#include "domain/tokenizer.h"
#include <sstream>
using namespace domain;
std::vector<std::string> Tokenizer::split(const std::string text, const std::string delimeter)
{
    std::vector<std::string> tokens;
    std::stringstream ss(text);
    std::string line;
    while (std::getline(ss, line))
    {
        std::size_t prev = 0, pos;
        while ((pos = line.find_first_of(delimeter, prev)) != std::string::npos)
        {
            if (prev < pos)
                tokens.push_back(line.substr(prev, pos - prev));
            prev = pos + 1;
        }
        if (prev < line.length())
            tokens.push_back(line.substr(prev, std::string::npos));
    }
    return tokens;
}
