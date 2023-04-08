#include "../headers.hpp"

std::vector<std::string> split_string(const std::string& str, char delimiter)
{
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream token_stream(str);
    while (std::getline(token_stream, token, delimiter))
        tokens.push_back(token);
    return tokens;
}